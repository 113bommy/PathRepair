from bisect import bisect_right, bisect_left
# instead of AVLTree
class BITbisect():
    def __init__(self, InputProbNumbers):
        # 座圧
        self.ind_to_co = [-10**18]
        self.co_to_ind = {}
        for ind, num in enumerate(sorted(list(set(InputProbNumbers)))):
            self.ind_to_co.append(num)
            self.co_to_ind[num] = ind+1
        self.max = len(self.co_to_ind)
        self.data = [0]*(self.max+1)
    
    def __str__(self):
        retList = []
        for i in range(1, self.max+1):
            x = self.ind_to_co[i]
            if self.count(x):
                c = self.count(x)
                for _ in range(c):
                    retList.append(x)
        return "[" + ", ".join([str(a) for a in retList]) + "]"
    
    def __getitem__(self, key):
        key += 1
        s = 0
        ind = 0
        l = self.max.bit_length()
        for i in reversed(range(l)):
            if ind + (1<<i) <= self.max:
                if s + self.data[ind+(1<<i)] < key:
                    s += self.data[ind+(1<<i)]
                    ind += (1<<i)
        if ind == self.max or key < 0:
            raise IndexError("BIT index out of range")
        return self.ind_to_co[ind+1]
    
    def __len__(self):
        return self._query_sum(self.max)
    
    def __contains__(self, num):
        if not num in self.co_to_ind:
            return False
        return self.count(num) > 0
    
    # 0からiまでの区間和
    # 左に進んでいく
    def _query_sum(self, i):
        s = 0
        while i > 0:
            s += self.data[i]
            i -= i & -i
        return s

    # i番目の要素にxを足す
    # 上に登っていく
    def _add(self, i, x):
        while i <= self.max:
            self.data[i] += x
            i += i & -i
    
    # 値xを挿入
    def push(self, x):
        if not x in self.co_to_ind:
            raise KeyError("The pushing number didnt initialized")
        self._add(self.co_to_ind[x], 1)
            
    # 値xを削除
    def delete(self, x):
        if not x in self.co_to_ind:
            raise KeyError("The deleting number didnt initialized")
        if self.count(x) <= 0:
            raise ValueError("The deleting number doesnt exist")
        self._add(self.co_to_ind[x], -1)

    # 要素xの個数
    def count(self, x):
        return self._query_sum(self.co_to_ind[x]) - self._query_sum(self.co_to_ind[x]-1)
    
    # 値xを超える最低ind
    def bisect_right(self, x):
        if x in self.co_to_ind:
            i = self.co_to_ind[x]
        else:
            i = bisect_right(self.ind_to_co, x) - 1
        return self._query_sum(i)

    # 値xを下回る最低ind
    def bisect_left(self, x):
        if x in self.co_to_ind:
            i = self.co_to_ind[x]
        else:
            i = bisect_left(self.ind_to_co, x)
        if i == 1:
            return 0
        return self._query_sum(i-1)

import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

Ind = [0]*(N+1)
for i, a in enumerate(A):
    Ind[a] = i+1

Bit = BITbisect(list(range(N+1)))
ans = [0]
Bit.push(Ind[1])
a = 0
for n in range(2, N+1):
    ind = Ind[n]
    f = Bit.bisect_left(ind)
    #print(Bit)
    l = len(Bit)
    if l%2 == 0:
        if f == l//2:
            a += l//2-l//2
        elif f < l//2:
            p1 = Bit[l//2-1]
            a += (p1-ind-1) - (l//2-1) + l-f
        else:
            p2 = Bit[l//2]
            a += (ind-p2-1) - (l//2-1) + l-f
    else:
        p1 = Bit[l//2]
        #print(f, p1, ind, l)
        if f <= l//2:
            a += (p1-ind-1) - l//2 + l-f
        else:
            a += (ind-p1-1) - l//2 + l-f
    ans.append(a)
    Bit.push(ind)


print(*ans, sep=" ")
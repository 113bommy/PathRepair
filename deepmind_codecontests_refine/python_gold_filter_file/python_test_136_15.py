
import sys, collections, math, bisect, heapq, random, functools,io,os,copy
input = sys.stdin.readline
out = sys.stdout.flush
def rep():
    a = list(map(int,input().split()))
    return a

def sep():
    a = list(input().split())
    return a


class UnionFind:
    def __init__(self, x) -> None:
        self.uf = [-1] * x

    def find(self, x):
        r = x
        while self.uf[x] >= 0:
            x = self.uf[x]

        while r != x:
            self.uf[r], r = x, self.uf[r]
        return x

    def union(self, x, y):
        ux, uy = self.find(x), self.find(y)
        if ux == uy:
            return
        if self.uf[ux] >= self.uf[uy]:
            self.uf[uy] += self.uf[ux]
            self.uf[ux] = uy
        else:
            self.uf[ux] += self.uf[uy]
            self.uf[uy] = ux
        return

    def __print__(self):
        return self.uf


def spfa(x,g,n):
    dis = [float('inf') for i in range(n)]
    dis[x] = 0
    state = [False for i in range(n)]
    state[x] = True
    queue = collections.deque()
    queue.append(x)
    while queue:
        cur = queue.popleft()
        state[cur] = False
        for next_ in g[cur]:
            if dis[next_] > dis[cur] + 1:
                dis[next_] = dis[cur] + 1
                if state[next_] == False:
                    state[next_] = True
                    queue.append(next_)
    return dis





def solve():
    n = int(input())
    a = rep()
    diff = []
    for i in range(n - 1):
        diff.append(a[i + 1] - a[i])
    t = sum(diff)
    flag = 1
    temp = []
    for i in range(len(diff)):
        if (diff[i] + t) % n:
            flag = 0
            break
        temp.append((diff[i] + t) // n)
    if not flag:
        print('NO')
    else:
        bsum = a[-1]
        tem = n - 1
        for i in range(len(diff)):
            bsum += tem * temp[i]
            tem -= 1
        q = n * (n + 1) // 2
        if bsum % q:
            print('NO')
        else:

            b1 = bsum // q
            ans = [b1]
            for i in range(len(temp)):
                ans.append(b1 - temp[i])

            flag = 1
            for c in ans:
                if c > 10 ** 9 or c < 1:
                    flag = 0
                    break
            if not flag:
                print('NO')
            else:
                print('YES')
                print(*ans)






if __name__ == '__main__':
    for i in range(int(input())):
        solve()
class SegTree():
    def segfunc(self, x, y):
        return x + y

    def __init__(self, ide, n, init_val):
        self.ide_ele = ide
        self.num = 2**(n-1).bit_length()
        self.seg = [self.ide_ele] * 2 * self.num
        for i in range(n):
            self.seg[i+self.num-1] = init_val[i]    
        for i in range(self.num-2,-1,-1):
            self.seg[i] = self.segfunc(self.seg[2*i+1],self.seg[2*i+2]) 
    def update(self, k, x):
        k += self.num-1
        self.seg[k] = x
        while k:
            k = (k-1)//2
            self.seg[k] = self.segfunc(self.seg[k*2+1], self.seg[k*2+2])
    def query(self, p, q):#p <= x < q
        if q<=p:
            return self.ide_ele
        p += self.num-1
        q += self.num-2
        res = self.ide_ele
        while q-p>1:
            if p&1 == 0:
                res = self.segfunc(res, self.seg[p])
            if q&1 == 1:
                res = self.segfunc(res, self.seg[q])
                q -= 1
            p = p//2
            q = (q-1)//2
        if p == q:
            res = self.segfunc(res, self.seg[p])
        else:
            res = self.segfunc(self.segfunc(res, self.seg[p]), self.seg[q])
        return res

def solve():
    n = int(input())
    camel = [list(map(int, input().split())) for _ in range(n)]
    camel_L = []
    camel_R = []
    for i in range(n):
        if camel[i][1] > camel[i][2]:
            camel_L.append([camel[i][0], camel[i][1], camel[i][2]])
        else:
            camel_R.append([camel[i][0], camel[i][1], camel[i][2]])
    ans = 0
    camel_L.sort(key=lambda x: (x[2]- x[1]))
    camel_R.sort(key=lambda x: (x[1]- x[2]))
    seg = SegTree(0, n, [0]*n)
    nex = [i for i in range(n)]
    for i in range(len(camel_L)):
        k, l, r = camel_L[i]
        q = seg.query(0, k)
        if q < k:
            p = nex[k-1]
            while p != nex[p]:
                pre = p
                p = nex[p]
                nex[pre] = nex[p]-1
            nex[p] = p-1
            seg.update(p, 1)
            ans += l
        else:
            ans += r
    seg = SegTree(0, n, [0]*n)
    nex = [i for i in range(n)]
    for i in range(len(camel_R)):
        k, l, r = camel_R[i]
        q = seg.query(k, n)
        if q < n-k:
            p = nex[k]
            while p != nex[p]:
                pre = p
                p = nex[p]
                nex[pre] = nex[p]+1
            nex[p] = p+1
            seg.update(p, 1)
            ans += r
        else:
            ans += l
    return ans

def main():
    t = int(input())
    ans = [None]*t
    for i in range(t):
        ans[i] = solve()
    for v in ans:
        print(v)

if __name__ == "__main__":
    main()
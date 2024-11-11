class SegTree:
    def __init__(self,arr,func,unit):
        self.func = func
        self.unit = unit
        n = 1
        while n < len(arr):
            n *= 2
        self.n = n
        nodes = [unit]*(2*n-1)
        nodes[n-1:n-1+len(arr)] = arr
        for i in range(n-2,-1,-1):
            nodes[i] = func(nodes[2*i+1],nodes[2*i+2])
        self.nodes = nodes

    def update(self,i,val):
        i += self.n-1
        self.nodes[i] = val
        while i >= 0:
            i = (i - 1) // 2
            self.nodes[i] = self.func(self.nodes[2*i+1], self.nodes[2*i+2])

    def query(self,l,r):
        l += self.n
        r += self.n
        s = self.unit
        while l < r:
            if r & 1:
                r -= 1
                s = self.func(self.nodes[r-1], s)
            if l & 1:
                s = self.func(s, self.nodes[l-1])
                l += 1
            l >>= 1
            r >>= 1
        return s

n, k = map(int, input().split())
A = [int(input()) for i in range(n)]

MAX = 300001

segt = SegTree([0] * MAX, lambda x, y: max(x, y), 0)
for a in A:
    l = max(0, a - k)
    r = min(MAX, a + k + 1)
    m = segt.query(l, r)
    segt.update(a, m + 1)

print(segt.query(0, MAX))

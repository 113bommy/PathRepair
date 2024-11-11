class SegmentTree():
    def __init__(self, n):
        self.n = n
        self.dp = [0 for _ in range(2 * n)]
        
    def update(self, k, a):
        k += self.n
        self.dp[k] = a
        while (k > 1):
            self.dp[k >> 1] = max(self.dp[k], self.dp[k ^ 1])
            k >>= 1
        
    def query(self, l, r):
        res = 0
        l, r = l + self.n, r + self.n
        while l < r:
            if l & 1:
                res = max(res, self.dp[l])
                l += 1
            if r & 1:
                res = max(res, self.dp[r - 1])
            l, r = l >> 1, r >> 1
        return res
    
    
n, k = map(int, input().split())
A = []
for _ in range(n):
    a = int(input())
    A.append(a)
num = max(A) + k + 1

st = SegmentTree(num)
for i in range(n):
    x = A[i]
    l = max(x - k, 0)
    r = min(x + k + 1, num)
    now = st.query(l, r) + 1
    st.update(x, now)
print(max(st.dp))    
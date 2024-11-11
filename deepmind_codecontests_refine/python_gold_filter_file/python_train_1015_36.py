import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    alst = [int(input()) for _ in range(n)]
    N = 300100
    
    ll = - 10 ** 10    
    LV = (N-1).bit_length()
    N0 = 2**LV
    data = [0]*(2*N0)
    lazy = [ll]*(2*N0)
    
    def gindex(l, r):
        L = (l + N0) >> 1; R = (r + N0) >> 1
        lc = 0 if l & 1 else (L & -L).bit_length()
        rc = 0 if r & 1 else (R & -R).bit_length()
        for i in range(LV):
            if rc <= i:
                yield R
            if L < R and lc <= i:
                yield L
            L >>= 1; R >>= 1
    
    def propagates(*ids):
        for i in reversed(ids):
            v = lazy[i-1]
            if v == ll:
                continue
            lazy[2*i-1] = data[2*i-1] = lazy[2*i] = data[2*i] = max(v, data[2*i-1], data[2*i])
            lazy[i-1] = ll
    
    def update(l, r, x):
        *ids, = gindex(l, r)
        propagates(*ids)
    
        L = N0 + l; R = N0 + r
        while L < R:
            if R & 1:
                R -= 1
                lazy[R-1] = data[R-1] = max(data[R-1], x)
            if L & 1:
                lazy[L-1] = data[L-1] = max(data[L-1], x)
                L += 1
            L >>= 1; R >>= 1
        for i in ids:
            data[i-1] = max(data[2*i-1], data[2*i])
    
    def query(l, r):
        propagates(*gindex(l, r))
        L = N0 + l; R = N0 + r
    
        s = 0
        while L < R:
            if R & 1:
                R -= 1
                s = max(s, data[R-1])
            if L & 1:
                s = max(s, data[L-1])
                L += 1
            L >>= 1; R >>= 1
        return s
    
    ans = 0
    for a in alst:
        a += 50
        l = max(0,a - k)
        r = min(a + k, 300099)
        xx = query(l, r + 1) + 1
        update(a, a + 1, xx)
        ans = max(ans, xx)
    print(ans)
    
main()

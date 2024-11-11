n,m = map(int,input().split())

def binSearch(n,m):
    lo = 1
    hi = n
    p = -1
    S = 0
    while(lo <= hi):
        k = (lo + hi) // 2
        S = ((k-1)* (k+2)) // 2
        S += m + 1
        if (n - S > 0):
            lo = k + 1
        else:
            p = k
            hi = k - 1
    return p

if (m>=n):
    print(n)
else:
    print(m + binSearch(n,m))
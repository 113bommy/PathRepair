n,m,a,b = input().split()

n,m,a,b = int(n), int(m), int(a), int(b)
ans=0
if n<=m:
    ans = min(a*n, b)
else:
    k = n//m
    ans = min(b*k, a*m*k) + min(b,a*(n-m*k))
print(ans)
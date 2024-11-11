n, m, a, b = map(int, input().split())
ans = 0
if n%m==0:
    pass
elif n<m:
    ans = min(b*n, a*(m-n))
else:
    ans = min(b*(n%m), a*(m-(n%m)))
print(ans)
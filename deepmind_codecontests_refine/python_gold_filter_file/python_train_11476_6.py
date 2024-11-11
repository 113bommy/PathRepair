n, mod = map(int, input().split())
A = list(map(int, input().split()))

if n > mod:
    print(0)
    exit()

ans = 1
for i in range(n-1):
    for j in range(i+1, n):
        ans *= abs(A[j]-A[i])
        ans %= mod
ans %= mod
print(ans)

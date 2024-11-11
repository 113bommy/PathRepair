n, k = map(int, input().split())

a = 0
for i in range(k, n+2):
    a += (n*i + i - i**2 + 1)

ans = a % (10**9+7)
print(ans)
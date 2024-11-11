n = int(input())
k = 10
ans = 0
if n % 2 == 0:
    while k <= n:
        ans += n // k
        k *= 5

print(ans)
n = int(input())
MOD = 10 ** 9 + 7

a = list(map(int, input().split()))

if n % 2 == 1:
    l = (n + 1) * (n - 1)
else:
    l = n ** 2

if sum(a) == l // 2:
    print(2 ** (n//2) % MOD)
else:
    print(0)


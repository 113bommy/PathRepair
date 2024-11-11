import sys

input = sys.stdin.readline

t = int(input())
for case in range(t):
    n, m = map(int, input().split())
    z = n - m
    g = m + 1
    if m == 0:
        print(0)
        continue
    if m == n:
        print(n * (n + 1) // 2)
        continue
    if m >= n // 2:
        print(n * (n + 1) // 2 - (n - m))
        continue

    k = z // g
    ans = n * (n + 1) // 2 - g * (k * (k + 1) // 2) - (z % g) * (k + 1)
    print(ans)
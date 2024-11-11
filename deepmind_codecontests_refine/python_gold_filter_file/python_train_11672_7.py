n, m, k, l = map(int, input().split())
res = 1 + (k + l - 1) // m
print(-1 if res * m > n else res)
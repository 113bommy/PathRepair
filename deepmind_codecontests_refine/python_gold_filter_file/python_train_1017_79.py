n, k, s = map(int, input().split())
l = [s] * k + [s+1 if s != 10**9 else 1] * (n-k)
print(*l)

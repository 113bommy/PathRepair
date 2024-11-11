n, l = map(int, input().split())
S = sorted([input() for _ in range(n)])
print(*S, sep='')
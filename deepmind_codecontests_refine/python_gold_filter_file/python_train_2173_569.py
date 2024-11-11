N, L = map(int, input().split())
S = sorted(input() for i in range(N))
print(*S, sep='')
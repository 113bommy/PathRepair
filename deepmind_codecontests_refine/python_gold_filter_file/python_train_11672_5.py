N, M, K, L = map(int, input().split())
t = ((K + L - 1) // M) + 1
if t * M <= N:
    print(t)
else:
    print(-1)

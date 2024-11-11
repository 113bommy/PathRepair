N = int(input())
F = [list(map(int, input().split())) for _ in range(N)]
P = [list(map(int, input().split())) for _ in range(N)]

ans = -float('inf')
for i in range(1, 1 << 10):
    bit = i
    profit = 0
    for j in range(N):
        cnt = sum(F[j][k] & (bit >> k) for k in range(10))
        profit += P[j][cnt]
    ans = max(ans, profit)

print(ans)

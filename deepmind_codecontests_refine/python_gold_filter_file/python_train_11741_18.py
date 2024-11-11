
N = int(input())
X = list(map(int, input().split()))

cnt = [0] * (N + 1)
cnt[0] = 1
for i in range(N):
    cnt[i + 1] = (cnt[i] - X[i]) * 2

ans = 0
cur = 0
for i in reversed(range(N + 1)):
    cur += X[i]
    ans += min(cnt[i], cur)

if all(cnt[i] >= X[i] for i in range(N + 1)):
    print(ans)
else:
    print(-1)

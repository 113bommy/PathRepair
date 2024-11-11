N = int(input())
s = [input() for _ in range(N)]

ans = 0
a = 0
for b in range(N):
    if all(s[(i - a) % N][(j - b) % N] == s[(j - a) % N][(i - b) % N] for i in range(N) for j in range(i + 1, N)):
        ans += N
print(ans)

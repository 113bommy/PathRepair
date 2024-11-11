N = int(input())
S = list(input())

s = [0]*(N+1)

for i in range(1, N+1):
    k = 0
    if S[i-1] == "W":
        k = 1
    s[i] = s[i-1] + k

ans = N
for i in range(1, N+1):
    k = (N - i) - (s[N] - s[i])
    ans = min(ans, k + s[i-1])


print(ans)

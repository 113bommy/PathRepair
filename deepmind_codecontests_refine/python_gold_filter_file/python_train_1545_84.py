N = int(input())
S = [input() for i in range(N)]
M = int(input())
T = [input() for i in range(M)]

ans = 0
for i in S:
    ans = max(ans, S.count(i) - T.count(i))

print(ans)
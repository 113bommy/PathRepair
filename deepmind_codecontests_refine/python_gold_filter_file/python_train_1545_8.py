N = int(input())
S = [input() for i in range(N)]
M = int(input())
T = [input() for i in range(M)]
ans = 0
for s in S:
    ans = max(ans, S.count(s) - T.count(s))
print(ans)

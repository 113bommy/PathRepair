N = int(input())
s = [input() for i in range(N)]
M = int(input())
t = [input() for i in range(M)]
ans = 0
for x in s:
    ans = max(ans, s.count(x) - t.count(x))
print(ans)
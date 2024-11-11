n = int(input())
s = [input() for i in range(n)]
m = int(input())
t = [input() for i in range(m)]

ans = 0

for w in s:
    ans = max(ans, s.count(w) -  t.count(w))

print(ans)
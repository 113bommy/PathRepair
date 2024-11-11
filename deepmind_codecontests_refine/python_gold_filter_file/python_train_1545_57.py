n = int(input())
s = [input() for i in range(n)]
m = int(input())
t = [input() for i in range(m)]
ss=set(s)
ans = [0]
for i in ss:
  ans.append(s.count(i)-t.count(i))
print(max(ans))
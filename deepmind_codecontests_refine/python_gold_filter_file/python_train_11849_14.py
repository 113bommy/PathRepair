from collections import Counter
n = int(input())
s = list(input())
c = Counter(s)
ans = 1
for x in c.values():
  ans = ans*(x+1)%(10**9+7)
print(ans-1)
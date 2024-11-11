from collections import defaultdict

def twosum(n):
  now = 1
  while n >= now:
    now *= 2
  return now - n
n=int(input())
a=sorted(list(map(int,input().split())))
d = defaultdict(int)
for i in a:
    d[i] += 1
ans = 0
for i in a[::-1]:
    d[i] -= 1
    find = twosum(i)
    if d[find] > 0 and d[i] >= 0:
        ans += 1
        d[find] -= 1
    else:
        d[i] += 1
print(ans)
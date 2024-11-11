import sys, itertools
input = sys.stdin.readline

n = int(input())
ll = []
for i in range(n):
  a = int(input())
  for j in range(a):
    x, y = map(int, input().split())
    ll.append([i, x-1, y])

ans = 0

for p in itertools.product([1,0], repeat=n):
  ok = 1
  for l in ll:
    if p[l[0]] == 1 and p[l[1]] != l[2]:
      ok = 0
      break
  if ok:
    ans = max(ans, sum(p))

print(ans)
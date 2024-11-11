import sys
n,k = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))
b = []
for i in range(n):
  for j in range(n):
    b.append(sum(a[i:j+1]))
    if b[-1] == 0:
      b.pop()
b.sort()
res = 0
for i in range(50,-1,-1):
  x = 1<<i
  ans = []
  for j in range(len(b)):
    if x&b[j]:
      ans.append(j)
  if len(ans) >= k:
    res += 1<<i
    c = []
    for l in ans:
      c.append(b[l])
    b = c
print(res)
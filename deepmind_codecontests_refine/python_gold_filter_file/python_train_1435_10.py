from collections import deque
n, m = map(int, input().split())
ab = [[] for i in range(n+1)]

for i in range(m):
  a, b = map(int,input().split())
  ab[a].append(b)
  ab[b].append(a)

ans = [-1]*(n+1)
que = deque([1])

while que:
  q = que.popleft()
  for i in ab[q]:
    if ans[i] == -1:
      que.append(i)
      ans[i] = q

print("Yes")

for i in range(2,n+1):
  print(ans[i])
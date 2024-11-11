from collections import deque

n, m = map(int, input().split())
friend = [set() for i in range(n)]
for i in range(m):
  a, b = map(int, input().split())
  friend[a-1].add(b-1)
  friend[b-1].add(a-1)

flag = [True for i in range(n)]
max_grupe = 0
for i in range(n):
  if(flag[i] == False):
    continue
  num = 0
  queue = deque([i])
  flag[i] = False
  while queue:
    now = queue.popleft()
    num += 1
    for j in friend[now]:
      if(flag[j]):
        queue.append(j)
        flag[j] = False
        
  max_grupe = max(max_grupe, num)
  
print(max_grupe)
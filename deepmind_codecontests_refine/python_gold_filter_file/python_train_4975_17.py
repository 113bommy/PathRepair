from collections import deque
N, *L = map(int, open(0).read().split())
E = [[] for i in range(N+1)]
for a,b  in zip(*[iter(L)]*2):
  E[a].append(b)
  E[b].append(a)
q = deque([1])
dist = [-1]*(N+1)
dist[1] = 0
dic = [[1],[]]
while q:
  u = q.popleft()
  for v in E[u]:
    if dist[v]==-1:
      dist[v] = dist[u]+1
      q.append(v)
      dic[dist[v]%2].append(v)

a = len(dic[0])
b = len(dic[1])
#print(dic)
seq = set(range(1,N+1))
ver = set(range(1,N+1))
ans = [0]*(N+1)
if a>N//3 and b>N//3:
  for i in range(1,N+1,3):
    v = dic[1].pop()
    ans[v] = i
  q = 0
  for i in range(2,N+1,3):
    v = dic[0].pop()
    ans[v] = i
  m = 3
  while dic[0]:
    v = dic[0].pop()
    ans[v] = m
    m += 3
  while dic[1]:
    v = dic[1].pop()
    ans[v] = m
    m += 3
elif a<=N//3:
  seq = set(range(1,N+1))
  m = 3
  while dic[0]:
    v = dic[0].pop()
    ans[v] = m
    seq.remove(m)
    m += 3
  seq = list(seq)
  while dic[1]:
    v = dic[1].pop()
    ans[v] = seq.pop()
else:
  seq = set(range(1,N+1))
  m = 3
  while dic[1]:
    v = dic[1].pop()
    ans[v] = m
    seq.remove(m)
    m += 3
  seq = list(seq)
  while dic[0]:
    v = dic[0].pop()
    ans[v] = seq.pop()
print(*ans[1:])
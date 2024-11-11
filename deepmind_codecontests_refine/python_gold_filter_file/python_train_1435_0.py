N, M = map(int, input().split())
E = [[] for _ in range(N)]
for _ in range(M):
  A, B = map(int, input().split())
  E[A-1] += [B-1]
  E[B-1] += [A-1]

ans = [-1]*N
T = [0]
while len(T)>0:
  P = T
  T = []
  for x in P:
    for e in E[x]:
      if ans[e]==-1:
        T += [e]
        ans[e] = x

print("Yes")
for a in ans[1:]:
  print(a+1)

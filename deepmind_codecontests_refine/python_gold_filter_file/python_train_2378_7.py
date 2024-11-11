import sys
sys.setrecursionlimit(10**7)

N, M = map(int,input().split())

michi = [[] for i in range(N)]
for i in range(M):
  tempa, tempb = map(int,input().split())
  michi[tempa-1].append(tempb-1)
  michi[tempb-1].append(tempa-1)
#print(michi)
  
colors = [0 for i in range(N)]

def dfs(v,color):
  colors[v] = color
  for to in michi[v]:
    if colors[to] == color:
      return False
    if colors[to] == 0 and not dfs(to,-color):
      return False
  return True

if dfs(0,1):
  a = colors.count(1)
  b = colors.count(-1)
  #print(colors)
  print(a*b-M)
else:
  print(N*(N-1)//2 - M)
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)
n=int(input())
s=list(map(int,list(input()[:-1])))
edge=[[]for _ in range(n)]
for _ in range(n-1):
  a,b=map(int,input().split())
  a-=1
  b-=1
  edge[a].append(b)
  edge[b].append(a)
def f(lrc):
  l1,r1,c1,x1=lrc[0]
  for l2,r2,c2,x2 in lrc[1:]:
    l1,r1=max(max(l1,l2)-min(r1,r2),0),r1+r2
    if r1%2!=l1%2:l1+=1
    c1+=c2
    x1+=x2
  return [l1,r1,c1,x1]
def dfs(root,node):
  lrcx=[]
  for mode in edge[node]:
    if root!=mode:
      lrcx.append(dfs(node,mode))
  if len(lrcx)==0:
    return [s[node]]*4
  l,r,c,x=f(lrcx)
  c+=s[node]
  return [l+c,r+c,c,x+c]
anss=[]
for i in range(n):
  l,r,c,x=dfs(-1,i)
  if l==c:
    anss.append(x-c)
if len(anss)==0:print(-1)
else:print(min(anss)//2)
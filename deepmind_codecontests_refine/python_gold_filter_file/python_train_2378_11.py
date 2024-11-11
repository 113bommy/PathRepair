import sys
input=sys.stdin.readline
n,m=map(int,input().split())
edge=[[] for i in range(n)]
for i in range(m):
  a,b=map(int,input().split())
  edge[a-1].append(b-1)
  edge[b-1].append(a-1)
Chk=[0]*n
Odd=False
T=[0]
Chk[0]=1
while T:
  t=T.pop()
  for g in edge[t]:
    if not Chk[g]:
      Chk[g]=Chk[t]*(-1)
      T.append(g)
    elif Chk[g]*Chk[t]==1:
      Odd=True
if Odd:
  print(n*(n-1)//2-m)
else:
  c=Chk.count(1)
  print(c*(n-c)-m)



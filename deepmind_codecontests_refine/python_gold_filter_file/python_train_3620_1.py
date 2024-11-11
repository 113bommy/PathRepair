from collections import defaultdict
N=int(input())

uddic=defaultdict(list)
lrdic=defaultdict(list)
uldic=defaultdict(list)
urdic=defaultdict(list)
dldic=defaultdict(list)
drdic=defaultdict(list)

for _ in range(N):
  XS,YS,U=input().split()
  x=int(XS)
  y=int(YS)
  if U=="U":
    uddic[x].append((y,U))
    uldic[x-y].append((x,U))
    urdic[x+y].append((x,U))
  elif U=="D":
    uddic[x].append((y,U))
    dldic[x+y].append((x,U))
    drdic[x-y].append((x,U))
  elif U=="L":
    lrdic[y].append((x,U))
    uldic[x-y].append((x,U))
    dldic[x+y].append((x,U))
  else:
    lrdic[y].append((x,U))
    urdic[x+y].append((x,U))
    drdic[x-y].append((x,U))
    
answer=float("inf")
#UD
for x in uddic:
  ylist=sorted(uddic[x])
  for i in range(len(ylist)-1):
    y1,u1=ylist[i]
    y2,u2=ylist[i+1]
    if u1=="U" and u2=="D":
      answer=min(answer,(y2-y1)*5)
#LR
for y in lrdic:
  xlist=sorted(lrdic[y])
  for i in range(len(xlist)-1):
    x1,u1=xlist[i]
    x2,u2=xlist[i+1]
    if u1=="R" and u2=="L":
      answer=min(answer,(x2-x1)*5)

#UL
for xmy in uldic:
  xlist=sorted(uldic[xmy])
  for i in range(len(xlist)-1):
    x1,u1=xlist[i]
    x2,u2=xlist[i+1]
    if u1=="U" and u2=="L":
      answer=min(answer,(x2-x1)*10)
#UR
for xpy in urdic:
  xlist=sorted(urdic[xpy])
  for i in range(len(xlist)-1):
    x1,u1=xlist[i]
    x2,u2=xlist[i+1]
    if u1=="R" and u2=="U":
      answer=min(answer,(x2-x1)*10)
#DL
for xpy in dldic:
  xlist=sorted(dldic[xpy])
  for i in range(len(xlist)-1):
    x1,u1=xlist[i]
    x2,u2=xlist[i+1]
    if u1=="D" and u2=="L":
      answer=min(answer,(x2-x1)*10)
#DR
for xmy in drdic:
  xlist=sorted(drdic[xmy])
  for i in range(len(xlist)-1):
    x1,u1=xlist[i]
    x2,u2=xlist[i+1]
    if u1=="R" and u2=="D":
      answer=min(answer,(x2-x1)*10)
  
if answer==float("inf"):
  print("SAFE")
else:
  print(answer)
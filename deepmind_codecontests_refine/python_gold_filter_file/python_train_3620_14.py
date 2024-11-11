N=int(input())
U,R,D,L=[],[],[],[]
for i in range(N):
  x,y,a=input().split()
  x,y=int(x),int(y)
  if a=='U':
    U.append((x,y))
  elif a=='R':
    R.append((x,y))
  elif a=='D':
    D.append((x,y))
  elif a=='L':
    L.append((x,y))

G={}
for x,y in U:
  if x not in G:
    G[x]=[(y,'U')]
  else:
    G[x].append((y,'U'))
for x,y in D:
  if x not in G:
    G[x]=[(y,'D')]
  else:
    G[x].append((y,'D'))  

time=10**10
for i in G.values():
  a=len(i)
  i=sorted(i)
  for j in range(a-1):
    if i[j][1]=='U' and i[j+1][1]=='D':
      t=(i[j+1][0]-i[j][0])*5
      time=min(t,time)
G={}
for x,y in R:
  if y not in G:
    G[y]=[(x,'R')]
  else:
    G[y].append((x,'R'))
for x,y in L:
  if y not in G:
    G[y]=[(x,'L')]
  else:
    G[y].append((x,'L'))  

for i in G.values():
  a=len(i)
  i=sorted(i)
  for j in range(a-1):
    if i[j][1]=='R' and i[j+1][1]=='L':
      t=(i[j+1][0]-i[j][0])*5
      time=min(t,time)
#UとR
G={}
for x,y in U:
  if x+y not in G:
    G[x+y]=[(y,'R')]
  else:
    G[x+y].append((y,'R'))
for x,y in R:
  if x+y not in G:
    G[x+y]=[(y,'U')]
  else:
    G[x+y].append((y,'U'))
for i in G.values():
  a=len(i)
  i=sorted(i) 
  for j in range(a-1):
    if i[j][1]=='R' and i[j+1][1]=='U':
      t=(i[j+1][0]-i[j][0])*10
      time=min(t,time)
#DとR
G={}
for x,y in D:
  if x-y not in G:
    G[x-y]=[(y,'D')]
  else:
    G[x-y].append((y,'D'))
for x,y in R:
  if x-y not in G:
    G[x-y]=[(y,'R')]
  else:
    G[x-y].append((y,'R'))
for i in G.values():
  a=len(i)
  i=sorted(i) 
  for j in range(a-1):
    if i[j][1]=='R' and i[j+1][1]=='D':
      t=(i[j+1][0]-i[j][0])*10
      time=min(t,time)
#DとL
G={}
for x,y in D:
  if x+y not in G:
    G[x+y]=[(y,'D')]
  else:
    G[x+y].append((y,'D'))
for x,y in L:
  if x+y not in G:
    G[x+y]=[(y,'L')]
  else:
    G[x+y].append((y,'L'))
for i in G.values():
  a=len(i)
  i=sorted(i) 
  for j in range(a-1):
    if i[j][1]=='L' and i[j+1][1]=='D':
      t=(i[j+1][0]-i[j][0])*10
      time=min(t,time)
#最後UL
G={}
for x,y in U:
  if x-y not in G:
    G[x-y]=[(y,'U')]
  else:
    G[x-y].append((y,'U'))
for x,y in L:
  if x-y not in G:
    G[x-y]=[(y,'L')]
  else:
    G[x-y].append((y,'L'))
for i in G.values():
  a=len(i)
  i=sorted(i) 
  for j in range(a-1):
    if i[j][1]=='U' and i[j+1][1]=='L':
      t=(i[j+1][0]-i[j][0])*10
      time=min(t,time)
if time==10**10:
  print('SAFE')
else:
  print(time)

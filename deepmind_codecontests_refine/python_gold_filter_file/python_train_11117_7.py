from sys import stdin as s
n,m=map(int,s.readline().split())
l=[0]*n
wa=[0]*n
cor,pen=0,0
for i in range(m):
  x,y=s.readline().split()
  x=int(x)-1
  if y=="AC":
    l[x]=1
  elif not l[x]:
    wa[x]+=1
for i in range(n):
  if l[i]:
    cor+=1
    pen+=wa[i]
print(cor,pen)
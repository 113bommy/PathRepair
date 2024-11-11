n,m=map(int,input().split())
l=[0]*(n+1)
p=0
for _ in range(m):
  a,b=list(input().split())
  if str(b)=="AC" and l[int(a)]!=-1:
    p+=l[int(a)]
    l[int(a)]=-1
  elif str(b)=="WA" and l[int(a)]!=-1:
    l[int(a)]+=1
print(l.count(-1),p)
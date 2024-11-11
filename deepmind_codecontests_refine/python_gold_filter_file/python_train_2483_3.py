n,m=map(int,input().split())
d=[0]*n
for i in range(m):
  a,b=map(int,input().split())
  d[a-1]+=1
  d[b-1]+=1
for i in d:
  print(i)
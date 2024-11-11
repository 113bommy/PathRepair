n,m=map(int,input().split())
li=[0]*n
for i in range(m):
  a,b=map(int,input().split())
  li[a-1]+=1
  li[b-1]+=1
for i in li:
  print(i)
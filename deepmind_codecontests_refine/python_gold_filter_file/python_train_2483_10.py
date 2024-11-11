n,m=map(int,input().split())
lis=[0]*n

for i in range(m):
  a,b=map(int,input().split())
  lis[a-1]+=1
  lis[b-1]+=1
  
for i in lis:
  print(i)
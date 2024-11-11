d=[0 for i in range(4)]
for i in range(3):
  a,b=map(int,input().split())
  d[a-1]+=1
  d[b-1]+=1
print(("NO","YES")[d.count(1)==2 and d.count(2)==2])

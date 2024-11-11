n,k,q=map(int,input().split())

lis=[0]*n

for i in range(0,q):
  lis[int(input())-1]+=1
for p in lis:
  if k-q+p>0:
    print("Yes")
  else:
    print("No")
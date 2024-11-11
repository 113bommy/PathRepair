a,b,k=map(int,input().split())
i,cnt=101,0
while cnt!=k:
  i-=1
  if a%i==0 and b%i==0:
    cnt+=1
print(i)
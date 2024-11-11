a,b,k=map(int,input().split())
ct=0
for i in range(100,-1,-1):
  if a%i==0 and b%i==0:
    ct+=1
  if ct==k:
    break
print(i)
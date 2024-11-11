n,k=map(int,input().split())
c=0
while n>=1:
  n/=k
  c+=1
print(c)
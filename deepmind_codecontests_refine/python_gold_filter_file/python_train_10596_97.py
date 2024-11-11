n,k=map(int,input().split())
x=0
while n>=1:
  n/=k
  x+=1
print(x)
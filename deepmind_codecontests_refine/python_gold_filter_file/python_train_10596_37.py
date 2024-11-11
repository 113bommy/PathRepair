n,k=map(int,input().split())
x=1
while n>=k:
  n=n//k
  x+=1
print(x)
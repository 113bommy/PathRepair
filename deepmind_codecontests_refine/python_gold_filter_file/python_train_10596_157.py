n,k=map(int,input().split())
i=1
while n>=k:
  n=n//k
  i+=1
print(i)
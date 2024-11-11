n,k=map(int,input().split())
l=[0]*(10**5+1)
for _ in range(n):
  a,b=map(int,input().split())
  l[a]+=b
for i in range(10**5+1):
  k-=l[i]
  if k<=0:
    print(i)
    break
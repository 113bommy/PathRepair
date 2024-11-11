n,k=map(int,input().split())
ab=[]
for _ in range(n):
  a,b=map(int,input().split())
  ab.append((a,b))
ab.sort()
for i,j in ab:
  k-=j
  if k<=0:
    print(i)
    exit()
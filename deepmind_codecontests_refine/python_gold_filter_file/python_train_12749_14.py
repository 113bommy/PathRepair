n,k=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
m=max(l[0],k-l[-1])*2
for i in range(n-1):
  m=max((l[i+1]-l[i]),m)
print(m*1./2)
  

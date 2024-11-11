n,k=map(int,input().split())
a=list(map(int,input().split()))
b=[0]*n
c=[0]*n
cnt=0
while cnt<min(k,101):
  cnt+=1
  for i in range(n):
    b[max(0,i-a[i])]+=1
    if i+a[i]<n-1:
      b[i+a[i]+1]-=1
    c[0]=b[0]
  for j in range(n-1):
    c[j+1]=c[j]+b[j+1]
  a=c
  b=[0]*n
  c=[0]*n
print(*a)
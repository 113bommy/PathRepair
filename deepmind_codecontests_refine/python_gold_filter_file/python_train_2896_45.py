n,k=map(int,input().split())
a=list(map(int,input().split()))
b=[]
for i in range(n):
  x=0
  for j in range(i,n):
    x+=a[j]
    b.append(x)
ans=0
l=len(b)
for i in range(40,-1,-1):
  x=0
  s=2**i
  for j in range(l):
    if b[j]&(ans+s)==ans+s:x+=1
  if x>=k:ans+=s
print(ans)
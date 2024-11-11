n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=0
for i in range(n):
  c+=min(a[i],b[i])
  d=b[i]-a[i]
  if d>0:
    c+=min(d,a[i+1])
  a[i+1]=min(a[i+1],max(0,a[i+1]-d))
print(c)  
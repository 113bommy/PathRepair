n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
num=0
for i in range(n):
  num+=min(a[i],b[i])
  b[i]=max(0,b[i]-a[i])
  num+=min(b[i],a[i+1])
  a[i+1]=max(0,a[i+1]-b[i])
print(num)
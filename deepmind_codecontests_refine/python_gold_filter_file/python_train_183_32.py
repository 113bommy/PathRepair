n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))
x=sum(b)
for i in range(len(a)-1):
  if a[i+1]-a[i]==1:
    d=a[i]
    x+=c[d-1]
print(x)

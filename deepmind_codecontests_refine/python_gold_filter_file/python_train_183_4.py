n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))
ct=sum(b)
for i in range(n-1):
  if a[i]+1==a[i+1]:
    ct+=c[a[i]-1]
print(ct)
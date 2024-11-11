n,k=map(int,input().split())
sum=k
tmp=k
for i in range(1,n):
  sum+=k+i
  if abs(tmp)>abs(k+i):
    tmp=k+i
print(sum-tmp)
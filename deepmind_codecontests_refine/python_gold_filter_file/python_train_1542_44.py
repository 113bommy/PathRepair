n=int(input())
a=list(map(int, input().split()))
a=[0]+a
b=[0]*(n+1)

for i in range(n,0,-1):
  sum=0
  for j in range(i+i,n+1,i):
    sum^=b[j]
  b[i]=sum^a[i]
ans=[]
for i in range(1,len(b)):
  if b[i]:
    ans.append(i)
print(len(ans))
print(*ans)
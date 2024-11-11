n=int(input())
a=list(map(int,input().split()))
a.sort(reverse=True)
ans=0
x=n
for i in range(1,n):
  ans+=a[i//2]
print(ans)

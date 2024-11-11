n=int(input())
a=list(map(int,input().split()))
a.sort(reverse=True)
ans=-max(a)
for i in range(n):
  ans+=a[i//2]
print(ans)
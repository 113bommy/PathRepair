n=int(input())
a=list(map(int,input().split()))
if 0 in a:exit(print(0))
ans=1
for i in a:
  ans*=i
  if ans>10**18:exit(print(-1))
print(ans)

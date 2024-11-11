N=int(input())
L=list(map(int,input().split()))
ans=1
L.sort()
flag=False
for i in L:
  ans=ans*i
  if ans>10**18:
    ans=-1
    break
print(ans)
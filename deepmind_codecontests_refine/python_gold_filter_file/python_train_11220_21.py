a=int(input())
b=list(map(int,input().split()))
b.sort()
ans=1
for i in range(a):
  ans=ans*b[i]
  if ans>10**18:
    ans=-1
    break
  
print(ans)

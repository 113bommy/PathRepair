n=int(input())
ans=n
for n1 in range(n+1):
  n2=n-n1
  cnt1=0
  while n1>0:
    cnt1+=n1%6
    n1=n1//6
  cnt2=0
  while n2>0:
    cnt2+=n2%9
    n2=n2//9
  ans=min(ans,cnt1+cnt2)
print(ans)
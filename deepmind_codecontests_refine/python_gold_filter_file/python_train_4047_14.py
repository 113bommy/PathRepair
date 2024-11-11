n=int(input())
tmp, ans=0,0
for i in range(n):
  a=int(input())
  if a==0:
    ans+=tmp//2
    tmp=0
  else:
    tmp+=a
print(ans+tmp//2)

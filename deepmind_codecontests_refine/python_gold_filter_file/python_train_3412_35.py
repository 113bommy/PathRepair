k=int(input())
ans='-1'
a=7
for i in range(1,10**6+1):
  if a%k==0:
    ans=i
    break

  a=((10*a)+7)%k
    
print(ans)
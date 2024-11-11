n=int(input())-1
ans=0
for i in range(1,n+1):
  ans+=n//i
print(ans)
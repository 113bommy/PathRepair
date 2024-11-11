N=int(input())
ans=0
for x in range(1,N):
  ans+=(N-1)//x
print(ans)

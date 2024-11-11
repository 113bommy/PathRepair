mod=10**9+7
n=int(input())
arr=list(map(int,input().split()))
acum=[1]
for i in range(2,n+1):
  tmp=acum[-1]+pow(i,mod-2,mod)
  tmp%=mod
  acum.append(tmp)
ans=0
for i in range(n-1):
  ans+=(arr[i+1]-arr[i])*acum[i]
  ans%=mod
for i in range(1,n):
  ans*=i
  ans%=mod
print(ans)
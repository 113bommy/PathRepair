from math import ceil
n=int(input())
arr=list(map(int,input().split()));dp=[]
if n==1:print(1);exit()
if arr[0]==0:print(1);exit()
for i in range(n):
 if arr[i]-i<=0:dp.append(0)
 else:
   k1=arr[i]-i;k=ceil(k1/n)
   dp.append(k)
cnt=10**18
for i in range(n):
  if dp[i]<cnt:cnt=dp[i];ans=i
print(ans+1)

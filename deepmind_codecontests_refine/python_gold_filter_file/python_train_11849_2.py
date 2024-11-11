n=int(input())
s=input()
mod=10**9+7
ans=1
lets=[1]*26
for i in s:
  lets[ord(i)-97]+=1
for i in range(26):
  ans*=lets[i]
  ans%=mod
print(ans-1)

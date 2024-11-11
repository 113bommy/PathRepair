s,m,ans=input()[::-1],int(1e9+7),0
for i in range(len(s)):
  if s[i]=='1':ans=(ans+pow(2,i,m))%m
print(ans*pow(2,len(s)-1,m)%m)
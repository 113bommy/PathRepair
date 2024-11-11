a,b=map(int,input().split())
ans=0
if a<=3:
    ans+=(4-a)*10**5
if b<=3:
    ans+=(4-b)*10**5
if a==b==1:
    ans+=4*10**5
print(ans)
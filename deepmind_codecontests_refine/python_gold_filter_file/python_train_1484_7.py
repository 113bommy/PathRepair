n=int(input())
l=list(map(int,input().split()))
pro=1
ans=[]
import math
pre=[0]*n
suf=[0]*n
pre[0]=l[0]
suf[n-1]=l[n-1]
ans=[]
for i in range(1,n):
    pre[i]=math.gcd(pre[i-1],l[i])
for i in range(n-2,-1,-1):
    suf[i]=math.gcd(suf[i+1],l[i])
#print(pre,suf)
for i in range(n):
    if i==0:
        u=math.gcd(l[i],suf[i+1])
    elif i==n-1:
        u=math.gcd(l[i],pre[i-1])
    else:
        u=math.gcd(l[i],math.gcd(pre[i-1],suf[i+1]))
    if i==0:
        ans.append((l[i]*suf[i+1])//u)
    elif i==n-1:
        ans.append((l[i]*pre[i-1])//u)
    else:
        ans.append((l[i]*math.gcd(pre[i-1],suf[i+1]))//u)
tot=ans[0] 
#print(ans)
for i in range(1,len(ans)):
    tot=math.gcd(tot,ans[i])
print(tot)
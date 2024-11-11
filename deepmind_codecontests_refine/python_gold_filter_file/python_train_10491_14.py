    #n,k,*a=map(int,open(0).read().split())
n, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
a.sort()
mod=10**9+7
ans=1
i=0
j=-1
kk=k
while kk>1:
    if a[i]*a[i+1]>a[j]*a[j-1]:
        ans=ans*a[i]*a[i+1]%mod
        i+=2
        kk-=2
    else:
        ans=ans*a[j]%mod
        j-=1
        kk-=1
if kk==1:
    ans=ans*a[j]%mod

if a[-1]<0 and k%2==1:
    ans=1
    for i in a[n-k:]:
        ans=ans*i%mod
print(ans)

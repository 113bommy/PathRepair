import math
l=10**9+7

n,a,b=map(int,input().split())
comb=[1]

for i in range(max(a,b)):
    den=i+1
    num=n-i
    ans=comb[i]*num*pow(den,l-2,l)%l
    comb.append(ans)


print((pow(2,n,l)-1-comb[a]-comb[b])%l)
def gcd(a,b):
    while b:
        a%=b
        a,b=b,a
    return a
n=int(input())
l=list(map(int,input().split()))
a=max(l)
g=a-l[0]
for i in range(1,n):
    g=gcd(g,a-l[i])
s=sum(l)
ans=a*n-s
ans=ans//g
print(ans,g)
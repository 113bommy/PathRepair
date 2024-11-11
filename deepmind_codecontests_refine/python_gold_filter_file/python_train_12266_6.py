from fractions import gcd
n,x=list(map(int, input().split()))
a=list(map(int, input().split()))
ans=a[0]-x
for i in a:
    ans=gcd(ans,abs(i-x))
print(ans)

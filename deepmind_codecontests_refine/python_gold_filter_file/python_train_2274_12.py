def gcd(a,b):
    while b!=0:
        a,b=b,a%b
    return a

n,k=map(int,input().split())
a=list(map(int,input().split()))
x=max(a)
for i in range(1,n):
    a[0]=gcd(a[0],a[i])
if k%a[0]==0 and k<=x:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
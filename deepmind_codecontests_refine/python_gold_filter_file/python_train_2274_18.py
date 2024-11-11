n,k=map(int,input().split())
a=list(map(int,input().split()))
def gcd(a,b):
    while b!=0:
        a,b=b,a%b
    return a
ans=a[0]
for i in range(1,n):
    ans=gcd(ans,a[i])
if k%ans==0:
    if k<=max(a):
        print("POSSIBLE")
        exit()
print("IMPOSSIBLE")

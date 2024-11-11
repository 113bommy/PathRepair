def gcd(x,y):
    if y== 0:
        return x
    else:
        return gcd(y,x%y)

res=0
n,m = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
for i in range(1,n):
    res = gcd(abs(a[i]-a[0]),res)
for j in range(m):
    print(gcd(b[j]+a[0],res),end=" ")

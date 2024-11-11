def oneLineArrayPrint(arr):
    print(' '.join([str(x) for x in arr]))

def gcd(x, y):
    while y != 0:
        (x, y) = (y, x % y)
    return x

n,m=[int(x) for x in input().split()]
a=[int(x) for x in input().split()]
b=[int(x) for x in input().split()]

ans=[]
if n>1:
    baseGCD=a[1]-a[0]
    for i in range(2,n):
        baseGCD=gcd(baseGCD,a[i]-a[0])

    for i in range(m):
        ans.append(gcd(baseGCD,a[0]+b[i]))
else:
    for i in range(m):
        ans.append(a[0]+b[i])

oneLineArrayPrint(ans)
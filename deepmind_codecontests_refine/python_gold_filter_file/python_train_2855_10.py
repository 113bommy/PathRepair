def __gcd(a,b):
    if b==0:
        return a
    return __gcd(b,a%b)

n =int(input())
a = list(map(int,input().split()))

gcd=a[0]
for i in range(1,len(a)):
    gcd = __gcd(a[i],gcd)

print(n*gcd)
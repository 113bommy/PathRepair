from fractions import gcd
n,m=map(int,input().split())
*a,=map(int,input().split())

g=a[0]
lcm=a[0]

for i in range(1,n):
    g=gcd(lcm,a[i])
    lcm*=a[i]
    lcm//=g

for i in range(n):
    if lcm//a[i]%2==0:
        print(0)
        exit(0)

print((2*m//lcm+1)//2)
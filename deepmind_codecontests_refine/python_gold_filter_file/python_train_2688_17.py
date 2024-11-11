from fractions import gcd


def lcm(x,y):
    return (x*y)//gcd(x,y)


n,m=map(int,input().split())
s,t=input(),input()
lcm=lcm(n,m)

if s[::int(lcm/m)]!=t[::int(lcm/n)]:
    print(-1);exit()

print(lcm)
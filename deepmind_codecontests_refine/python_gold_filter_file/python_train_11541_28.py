import fractions
n,m,a=map(int,input().split())
if a%fractions.gcd(n,m)==0:
    print("YES")
else:
    print("NO")
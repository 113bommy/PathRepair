import fractions
a,b,c=map(int,input().split())
if c%fractions.gcd(a,b)==0:
    print("YES")
else:
    print("NO")
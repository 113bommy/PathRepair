import fractions
n,m=map(int,input().split())
s=input()
t=input()
b=0
for i in range(n):
    if (i*m)%n==0 and (i*m)//n<m:
        if not t[(i*m)//n]==s[i]:
            b=1

if b:
    print(-1)
else:
    print(n*m//fractions.gcd(n,m))
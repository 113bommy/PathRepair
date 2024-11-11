from fractions import gcd 
n,x=map(int,input().split())
s=list(map(int,input().split()))
b=s[0]
t=abs(b-x)
for i in range(1,n):
    t=gcd(t,abs(s[i]-x))   
print(t) 
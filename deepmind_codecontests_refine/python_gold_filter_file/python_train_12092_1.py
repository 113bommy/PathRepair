import sys
input = sys.stdin.readline

n,k=map(int,input().split())
a,b=map(int,input().split())

a=a%k
MIN=10**12
MAX=0

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

for i in range(n):
    ne=i*k-b
    dist=abs(a-ne)

    #print(ne,dist)

    if dist==0:
        dist=n*k

    ANS=n*k//gcd(dist,n*k)

    if ANS<MIN:
        MIN=ANS
    if ANS>MAX:
        MAX=ANS

    ne=i*k+b
    dist=abs(a-ne)

    if dist==0:
        dist=n*k

    #print(dist)

    ANS=n*k//gcd(dist,n*k)

    if ANS<MIN:
        MIN=ANS
    if ANS>MAX:
        MAX=ANS

print(MIN,MAX)
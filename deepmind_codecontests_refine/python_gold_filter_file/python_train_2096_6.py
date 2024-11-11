import math
for _ in range(int(input())):
    a=int(input())
    g=math.gcd(180,a)
    k=a//g
    n=180//g 
    if  k+1==n:
        n*=2 
    print(n)
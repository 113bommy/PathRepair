from math import *
for u in range(int(input())):
    x,y=map(int,input().split())
    g=gcd(x,y)
    if(g>1):
        print("Infinite")
    else:
        print('Finite')

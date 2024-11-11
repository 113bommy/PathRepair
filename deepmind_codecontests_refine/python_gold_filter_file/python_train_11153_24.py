import math as ma
import sys
from sys import exit
from decimal import Decimal as dec
from itertools import permutations


def li ():
    return list (map (int, input ().split ()))


def num ():
    return map (int, input ().split ())


def nu ():
    return int (input ())

mm=1000000007
t=1
for it in range(t):
    n=nu()
    s=input()
    x=["RGB","RBG","BRG","BGR","GRB","GBR"]
    y=999999999999
    pp=""
    for i in range(6):
        ss=0
        pq=""
        for j in range(n):
            if(x[i][j%3]!=s[j]):
                ss+=1
                pq+=x[i][j%3]
            else:
                pq+=x[i][j%3]
        if(ss<y):
            pp=pq
            y=ss
    print(y)
    print(pp)
from math import ceil,sqrt,gcd,log,floor
from collections import deque
def ii(): return int(input())
def si(): return input()
def mi(): return map(int,input().strip().split(" "))
def li(): return list(mi())
def msi(): return map(str,input().strip().split(" "))
def lsi(): return list(msi())
#for _ in range(ii()):
x=[]
for i in range(3):
    x.append(li())
for i in range(3):
    for j in range(3):
        s=x[i][j]
        if(i>0):
            s+=x[i-1][j]
        if(j>0):
            s+=x[i][j-1]
        if(i<2):
            s+=x[i+1][j]
        if(j<2):
            s+=x[i][j+1]
        if(s%2==0):
            print('1',end="")
        else:
            print('0',end="")
    print()
    

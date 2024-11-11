from sys import stdin,stdout
from collections import defaultdict
input=stdin.readline
#print=stdout.write
from random import randint
import math
import sys 
#sys.setrecursionlimit(10**5)
###-----------Code Begins----------##


def oper1(x):
    bin=[]
    y=x
    while(y>0):
        bin.append(y%2)
        y= y>>1
    new = 0
    for i in range(len(bin)):
        new = (new<<1)+ bin[i]
    return new

def oper2(x):
    bin=[1]
    y=x
    while(y>0):
        bin.append(y%2)
        y= y>>1
    new = 0
    for i in range(len(bin)):
        new = (new<<1)+ bin[i]
    return new


X,Y = map(int,input().split())
x,y= X,Y

answer = False

if(x==y):
    answer=True

targety= []
while(y>0):
    targety.append(str(y%2))
    y= y//2

targety = "".join(reversed(targety))


def checkpossible(XX, targety):
    x= XX
    startx= []
    while(x>0):
        startx.append(str(x%2))
        x=x//2
    startx.reverse()
    startx = "".join(startx)
    
    if(len(startx)>len(targety)):
        return False
    
    if(startx== targety):
        return True
    
    for i in range(len(targety)):
        match = True
        for j in range(len(startx)):
            if( i+j>len(targety)-1 or targety[i+j]!= startx[j]):
                match= False
                break
        if(match== True):
            if( (i==0 or targety[0:i].find("0")==-1) and (targety[i+len(startx)::].find("0")==-1) and (False==(i+len(startx)==len(targety) and startx[-1]=="0" )) ):
                return True
    return False

answer = answer or checkpossible(X, targety) or checkpossible(oper1(X), targety) or checkpossible(oper2(X), targety)

answer = answer or checkpossible(oper1(oper1(X)), targety) or checkpossible(oper1(oper1(X)), targety) or checkpossible(oper2(oper1(X)),targety)

if(answer):
    print("YES")
else:
    print("NO")



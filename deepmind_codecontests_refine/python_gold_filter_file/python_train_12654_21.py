import sys, os.path
from collections import*
from copy import*
import math
mod=10**9+7
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")   

n=int(input())
mat=[]
for i in range(n):
    l=list(map(int,input().split()))
    mat.append(l)
if(n==1):
    print(1)
else:
    x=0
    y=0
    for i in range(n):
        for j in range(n):
            if(mat[i][j]==0):
                x=i
                y=j
    r=0
    r1=0
    for i in range(n): 
        r+=mat[x][i]
    if(x!=0):
        for i in range(n): 
            r1+=mat[0][i]
    else:
        for i in range(n): 
            r1+=mat[1][i]
    mat[x][y]=abs(r1-r)
    flag=0
    sm=0
    sm2=0
    for i in range(n):
        sm=0
        sm2=0
        for j in range(n):
            sm+=mat[i][j]
            sm2+=mat[j][i]
        if(sm!=r1 or sm2!=r1):
            flag=1
            break
    sm=0
    sm2=0
    for i in range(n):
        sm+=mat[i][i]
        sm2+=mat[i][n-i-1]
    
    if(sm!=r1 or sm2!=r1):
        flag=1

    if(flag==0 and mat[x][y]!=0):
        print(mat[x][y])
    else:
        print(-1)







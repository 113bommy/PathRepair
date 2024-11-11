from sys import stdin,stdout
def INPUT():return list(int(i) for i in stdin.readline().split())
def inp():return stdin.readline()
def out(x):return stdout.write(x)
import math
import random
########################################################
for _ in range(int(input())):
    n=int(input())
    A=INPUT()
    B=A.copy()
    B.sort()
    if A==B:
        print("YES")
        continue
    d=min(A)
    bool=True
    for  i in range(n):
        if A[i]!=B[i]:
            if A[i]%d!=0:
                #print(A[i],B[i])
                bool=False
                break
    if bool:
        print("YES")
    else:
        print("NO")

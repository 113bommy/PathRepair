import math
import sys
w,h=map(int,sys.stdin.readline().split())          
w1,h1=map(int,sys.stdin.readline().split())
w2,h2=map(int,sys.stdin.readline().split())
for t in range(1,h+1,1):
    i=h+1-t
    w=w+i
    if (i==h1):
        w=w-w1
    elif (i==h2):
        w=w-w2
    if (w<=0):
        w=0
print(w)
    
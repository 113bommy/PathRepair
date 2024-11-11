# import sys
# sys.stdin=open("input.in",'r')
# sys.stdout=open("out1.out",'w')
import math
n,x,y=map(int,input().split())
a=(n*y-x*100)/100
print(max(0,math.ceil(a)))
import sys
import math
input = sys.stdin.readline
 
t = int(input())
 
for x in range(t+1000, t+1105):
    if x%2==0 and (x+t)%3==0:
        print(x+t, x)
        exit()
import sys
import math

n = sys.stdin.readline()
n = int(n)

for i in range(n):
    
    q = sys.stdin.readline()
    q = int(q)
    
    try:
        a = (-q +  math.sqrt(q**2 - 4*q))/(-2)
        b = q - a
        print('Y', a,b)
    except:
        print('N')
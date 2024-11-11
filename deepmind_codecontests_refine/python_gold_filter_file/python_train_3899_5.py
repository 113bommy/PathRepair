# -*- coding: utf-8 -*-
import sys
f = sys.stdin
#f = open('H:\\Portable Python 3.2.5.1\\test_248B1.txt') 
n, v  = map(int, f.readline().strip().split())

p = [0]*3002
for i in range(n):
    a, b  = map(int, f.readline().strip().split())
    p[a] += b
#print(p[:5])    
S = 0
for k in range(1,len(p)):
    dv = min(v,p[k-1])
    S += dv
    p[k-1] -= dv    

    dv = min(v-dv,p[k])    
    S += dv
    p[k] -= dv      
    #print(k, S, v, dv, p[:5])   
print(S)


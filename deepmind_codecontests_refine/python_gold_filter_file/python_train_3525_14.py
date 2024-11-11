import sys
import math
n = int(input())
T,A = 1,1
for i in range(n):
    t,a = map(int,input().split())
    coef = max((T+t-1)//t,(A+a-1)//a)
    T,A = coef * t, coef * a 
print(T+A)     

    

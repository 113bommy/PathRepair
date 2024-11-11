import math
import time

h,m = list(map(int,input().split()))

hunger,decr,cost,n = list(map(int,input().split()))

if h >= 20:
    b = hunger//n;
    if hunger%n != 0 : b += 1
    print(0.8*b*cost)
else:
    b = hunger//n;
    if hunger%n != 0 : b += 1
    a = b*cost
    t = 20*60 - h*60-m
    hunger += t*decr
    b = hunger//n;
    if hunger%n != 0 : b += 1
    c = 0.8*b*cost
    print(min(a,c))
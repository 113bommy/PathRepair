import sys
import math
import time

'''
c = int(input())
a = [int(j) for j in input().split()]
'''

n, v = [int(j) for j in input().split()]

cost = min(n-1,v)
fuel = min(n-1,v)

for i in range(n):
    
    dist = n-i-1
    if fuel == dist:
        break
    else:
        extra = min(dist, v-fuel)
        fuel += extra
        cost += (i+1)*extra
    fuel -= 1
    
print(cost)
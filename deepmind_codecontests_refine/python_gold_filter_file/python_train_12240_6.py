
def STR(): return list(input())
def INT(): return int(input())
def MAP(): return map(int, input().split())
def MAP2():return map(float,input().split())
def LIST(): return list(map(int, input().split()))
def STRING(): return input()
import string
import sys
from heapq import heappop , heappush
from bisect import *
from collections import deque , Counter , defaultdict
from math import *
from itertools import permutations , accumulate
dx = [-1 , 1 , 0 , 0  ]
dy = [0 , 0  , 1  , - 1]
#visited = [[False for i in range(m)] for j in range(n)]
#sys.stdin = open(r'input.txt' , 'r')
#sys.stdout = open(r'output.txt' , 'w')
#for tt in range(INT()):


#CODE


n , m, k = MAP()
f = k
r1 , r2 = -1 , -1

lans = []
for i in range(1 , n + 1):
    lans.append(2 * m * i)

#print(lans)

for i in range(n):
    if lans[i] == k :
        r1 = i + 1
        break
    else:
        if lans[i] > k :
            r1 = i + 1
            break
        else:
            continue

desk = []
for i in range(1 , m+1):
    desk.append(i * 2)

while k > 2 * m :
    k-= 2 * m

#print(k)
if k % 2 != 0 :
    k +=1

r2 = bisect_left(desk , k)

r3 = "L"
if f % 2 == 0:
    r3 = "R"

print(r1, r2 + 1, r3)




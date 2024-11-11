from collections import Counter,defaultdict,deque
import heapq as hq
from itertools import count, islice

#alph = 'abcdefghijklmnopqrstuvwxyz'
#from math import factorial as fact
import math
import sys
input=sys.stdin.readline
#print=sys.stdout.write
#tt = int(input())
#total=0
#n = int(input())
#n,m,k = [int(x) for x in input().split()]
#n = int(input())
#l,r = [int(x) for x in input().split()]
n = int(input())
k = int(input())
a = int(input())
b = int(input())
total = 0
if k==1:
    print(a*(n-1))
    exit()
while n!=1:
    rem = n%k
    if n<k:
        total+=a*(rem-1)
        break
    if rem:
        n-=rem
        total+=rem*a
    else:
        total+=min((n-n//k)*a,b)
        n//=k
print(total)

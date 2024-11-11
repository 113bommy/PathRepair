import sys
import math
from collections import OrderedDict
def input():    return sys.stdin.readline().strip()
def iinput():   return int(input())
def minput():   return map(int, input().split()) 
def listinput(): return list(map(int, input().split()))
n,k=minput()
l=listinput()
l1=[]
for i in range(k):
	l1.append(n%l[i])
m1=min(l1)
m2=l[l1.index(m1)]
print(l1.index(m1)+1,(n//m2))
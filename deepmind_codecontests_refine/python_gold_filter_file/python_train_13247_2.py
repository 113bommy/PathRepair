import sys 
from collections import defaultdict as dd
from collections import Counter as cc
from queue import Queue
import math
import itertools
try:
	sys.stdin = open('input.txt', 'r') 
	sys.stdout = open('output.txt', 'w')
except:
	pass
# input = lambda: sys.stdin.buffer.readline().rstrip()


q=int(input())
w=input()
e=input()
r=[]
if w.count('1')!=e.count('1'):
	print(-1)
	exit()
if w.count('1')==q or w.count('1')==0:
	print(0)
	exit()
for i in range(q):
	if w[i]!=e[i]:
		r.append(e[i])
k=0
l=[]
for i in r:
	if i=='1':
		k+=1
	else:
		k-=1
	l.append(k)
print(max(l)+abs(min(l)))
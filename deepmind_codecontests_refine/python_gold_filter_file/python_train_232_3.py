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
input = lambda: sys.stdin.buffer.readline().rstrip()

q=int(input())
w=list(map(int,input().split()))
if q==1:
	print(1,1)
	print(-w[0])
	print(1,1)
	print(0)
	print(1,1)
	print(0)
else:
	print(1,1)
	print(-w[0])
	print(2,q)
	print(*([(q-1)*w[i] for i in range(1,q)]))
	print(1,q)
	print(*([0]+[-(q)*w[i] for i in range(1,q)]))
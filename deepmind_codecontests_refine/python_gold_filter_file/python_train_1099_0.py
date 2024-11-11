from sys import stdin,stdout
from collections import Counter
def ai(): return list(map(int, stdin.readline().split()))
def ei(): return map(int, stdin.readline().split())
def ip(): return  int(stdin.readline().strip())
def op(ans): return stdout.write(str(ans) + '\n')

import math
n= ip()
if n==0:
	print(1);exit()
x = n%4
if x == 0:
	x = 4
print(str(8**x)[-1])
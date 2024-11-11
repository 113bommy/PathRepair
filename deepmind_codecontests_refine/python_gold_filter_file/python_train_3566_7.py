
from sys import stdin,stdout
stdin.readline
def mp(): return list(map(int, stdin.readline().strip().split()))
def it():return int(stdin.readline().strip())
from collections import defaultdict as dd,Counter as C,deque
from math import ceil,gcd


def maxsubarraysum(l):

	pre = 0
	ans = float('-inf')

	for i in l:
		pre += i
		ans = max(ans,pre)
		if pre < 0:
			pre = 0
	return ans

for _ in range(it()):
	n  =it()
	l = mp()
	e,o=[],[]
	es,os=0,0
	for i in range(1,n,2):
		e.append(l[i]-l[i-1])
		
	for j in range(1,n-1,2):
		o.append(l[j]-l[j+1])

	for i in range(n):
		if not i&1:
			es+=l[i]
		else:
			os+=l[i]
	k1 = maxsubarraysum(o)
	k2 = maxsubarraysum(e)
	k = max(k1,k2)
	# print(k)
	if k >0:
		es+=k
	print(es)


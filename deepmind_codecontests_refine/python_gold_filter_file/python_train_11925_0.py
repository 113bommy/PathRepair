from itertools import *
from math import *
n, m = map(int, input().split())
x = ceil(log(m,7))
y = ceil(log(n,7))
ms = dict()
x = max(1,x)
y = max(1,y)
def conv(s):
	s = s[::-1]
	j = 0
	num = 0
	for i in s:
		num += int(i)*7**j
		j+=1
	# print(num)
	return num
if x+y > 7:
	print(0)
else:
	s = '0123456'
	ans = 0
	for i in permutations(s,x+y):
		# print(i)
		
		a = i[:y]
		b = i[y:x+y]
		# print(a,b)
		if len(a) == 0 or len(b) == 0:
			continue
		if conv(a)<n and conv(b)<m:
			# print(conv(a),conv(b),i)
			ans +=1
	print(ans)
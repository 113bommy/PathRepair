# http://codeforces.com/contest/78/problem/B
import math
n = int(input())
base = 'ROYGBIV'

base_l = list(base)

for i in range(n//len(base) - 1):
	base_l.extend(list(base))
lp=0
rp=len(base)

for i in range(len(base) - n%len(base)):
	if i%2 ==0:
		lp+=1
	else:
		rp-=1
# print(lp, rp)
base_l.extend(list(base)[lp:rp])
print("".join(base_l))
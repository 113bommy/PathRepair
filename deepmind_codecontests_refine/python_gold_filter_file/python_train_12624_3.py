
from sys import stdin,stdout
stdin.readline
def mp(): return list(map(int, stdin.readline().strip().split()))
def it():return int(stdin.readline().strip())
from collections import defaultdict as dd,Counter as C


for _ in range(it()):
	n = it()
	l = list(input())
	o,z=[],[]
	x=1
	ans=[0]*n
	if n == 1:
		print(1)
		print(1)
	else:
		for i in range(n):
			if l[i] == '0':
				if o:
					t = o.pop()
					ans[i]=t
					z.append(t)
				else:
					z.append(x)
					ans[i] = x
					x+=1
			else:
				if z:
					t = z.pop()
					ans[i]=t
					o.append(t)
				else:
					o.append(x)
					ans[i]=x
					x+=1
		print(max(ans))
		print(*ans)

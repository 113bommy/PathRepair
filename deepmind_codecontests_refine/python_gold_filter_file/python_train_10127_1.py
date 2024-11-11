import sys
import math
def II():
	return int(sys.stdin.readline())

def LI():
	return list(map(int, sys.stdin.readline().split()))

def MI():
	return map(int, sys.stdin.readline().split())

def SI():
	return sys.stdin.readline().strip()
t = II()
for q in range(t):
	n, q = MI()
	a = LI()
	ans = []
	i = 1
	temp = a[0]
	asc = True
	while i<n:
		if asc and a[i]>temp:
			temp = a[i]
		elif asc:
			ans.append(temp)
			temp = a[i]
			asc = False
			i+=1
			continue
		elif asc == False and a[i]<temp:
			temp = a[i]
		else:
			ans.append(temp)
			temp = a[i]
			asc = True
			continue
		i+=1
	if ans == [] or temp>ans[-1]:
		ans.append(temp)
	aa = 0
	for i in range(len(ans)):
		if i%2 == 0:
			aa+=ans[i]
		else:
			aa-=ans[i]
	print(aa)
# code by RAJ BHAVSAR
from collections import deque
n,q = map(int,input().split())
arr = list(map(int,input().split()))
temp = [arr[0]]
for i in range(n-1):
	a,b = temp[i],arr[i+1]
	if(a < b):
		a,b = b,a
	temp.append(a)
	arr.append(b)
while(q):
	q -= 1
	m = int(input())
	if(m <= n):
		print(temp[m-1],arr[m])
	else:
		print(temp[-1],arr[n + (m-n)%(n-1)])
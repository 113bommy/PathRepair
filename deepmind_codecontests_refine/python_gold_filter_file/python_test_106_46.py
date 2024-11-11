import math
t = int(input())
for i in range(t):
	n = int(input())
	lst = [i+1 for i in range(1,n+1)]
	print(*lst)
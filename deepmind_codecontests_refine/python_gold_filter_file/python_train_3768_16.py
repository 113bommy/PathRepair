import math
for _ in range(int(input())):
	n = int(input())
	p = list(map(int,input().split()))
	sum_ = sum(p)
	a = math.ceil(sum_/n)
	print(a)
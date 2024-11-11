import math
for _ in range(int(input())):
	n=int(input())
	A=[int(i) for i in input().split()]
	avg=math.ceil(sum(A)/n)
	print(avg)
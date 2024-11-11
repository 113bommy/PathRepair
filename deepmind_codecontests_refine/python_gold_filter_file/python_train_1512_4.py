n = int(input())
m = [int(x) for x in input().split()]
avg = sum(m)//(len(m))
if avg * n == sum(m):
	print(sum([max(0,avg-x) for x in m]))
else:
	x = sum([max(0,x-avg-1) for x in m])
	y = sum([max(0,avg-x) for x in m])
	print(max(x,y))
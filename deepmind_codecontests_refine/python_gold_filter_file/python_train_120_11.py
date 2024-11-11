n = int(input())

elems = []
for _ in range(n):
	elems.append(tuple(map(int, input().split())))


def solve(elem):
	a,b,c = elem

	temp = 0
	while 2*temp<=c and temp<=b:
		temp += 1

	t1 = temp-1
	a,b,c = a,b-t1,c-2*t1

	temp = 0
	while 2*temp<=b and temp<=a:
		temp += 1
	t2 = temp-1
	#a,b,c = a-t2,b-2*t2,c
	print(t1+2*t1+t2+2*t2)


for elem in elems:
	solve(elem)




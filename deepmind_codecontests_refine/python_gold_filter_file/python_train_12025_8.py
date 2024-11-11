days = int(input())
a, p =[int(i) for i in input().split()]
counter = a*p
minp = p
for i in range(days-1):
	a, p =[int(i) for i in input().split()]
	if p < minp:
		minp = p
	counter += a*minp
print(counter)
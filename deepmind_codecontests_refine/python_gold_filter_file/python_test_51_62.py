# your code goes here.

for _ in range(int(input())):
	x = int(input())
	
	if x==0: print("-1 1");continue
	
	step = 0
	while x%2 == 0:
		x = x//2
		step+=1
	step = 2**step
	
	l = x//2
	print(int(l - step +1), end = " ")
	print(int(l + step))
	
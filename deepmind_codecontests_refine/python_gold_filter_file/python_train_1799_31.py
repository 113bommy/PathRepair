# code by RAJ BHAVSAR
for _ in range(int(input())):
	x = int(input())
	ans = 0
	for i in range(1,40):
		temp = 2**i - 1
		summ = (temp*(temp+1))//2
		if(x >= summ):
			x -= summ
			ans += 1
	print(ans)
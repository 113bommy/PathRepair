T = int(input())
for _ in range(T):
	a,b,n = list(map(int,input().split()))
	s=max(a,b)
	step=0
	while s<=n:
		s =a+b
		a = max(a,b)
		b = s
		step+=1
	print(step)

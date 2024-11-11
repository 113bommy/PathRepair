n=int(input())
for i in range(n):
	a,b=map(int,input().split())
	s=list(map(int,input().split()))
	s.sort()
	x=s[0]
	y=s[-1]
	if y-x>2*b:
		print(-1)
	else: print(x+b)
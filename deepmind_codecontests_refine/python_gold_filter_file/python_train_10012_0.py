t=int(input())
while t:
	t-=1
	n=int(input())
	a=list(map(int,input().split()))
	a.sort(reverse=True)
	count=0
	a.pop(0)
	x=a.pop(0)
	for i in a:
		if x>count+1:
			count+=1
	print(count)
x=int(input())
for _ in range(x):
	num=list(map(int,input().split()))
	b,c=0,0
	flag=True
	for i in num:
		if b<i:
			b=i
		elif c<i:
			c=i
		else:
			print("NO")
			flag=False
			break
	if flag:
		print("YES")

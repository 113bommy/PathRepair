num=int(input())
for _ in range (num):
	n=int(input())
	ls=[]
	sum=0
	val=1
	for i in range(1,n+1):
		sum+=val
		ls.append(val)
		if sum>=n:
			break
		val+=2
	print(len(ls))
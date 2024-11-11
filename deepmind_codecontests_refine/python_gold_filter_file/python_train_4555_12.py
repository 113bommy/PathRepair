a=int(input())
b=list(map(int,input().split()))
c=0
b.sort()
if int(round(sum(b)/a+0.00001))==5:
	print(0)
else:
	for i in range(a):
		if b[i]<5:
			b[i]=b[i]+(5-b[i])
			c+=1
		if int(round((sum(b)/a+0.00001)))==5:
			print(c)
			exit()

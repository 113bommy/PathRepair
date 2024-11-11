import math
n,x=map(int,input().split())
if n<=9:
	if n==1 and x==1:
		print (0)
		exit()
	if x==1:
		ans=[2]
	else:
		ans=[1]
	temp=ans[0]^x
	d={ans[0]:1,temp:1}
	while True:
		flag=0
		for i in range(1,2**n):
			if i!=x and i not in d:
				ans.append(i)
				flag=1
				break
		if not flag:
			break
		xor=0
		d={}
		for i in range(len(ans)-1,-1,-1):
			xor=xor^ans[i]
			if xor not in d:
				d[xor^x]=1
				d[xor]=1
		# print (d,ans)
	print (len(ans))
	print (*ans)
else:
	v=2**(int(math.log(x,2)))
	value=[]
	for i in range(19):
		value.append(2**i)
	value=value[::-1]
	if x<2**(n)-1:
		v=2**(int(math.log(x,2)))
		print (2**(n-1)-1)
		ans=[]
		for i in range(1,2**(n-1)):
			for j in value:
				if i%j==0:
					if j%v==0 or j%x==0:
						ans.append(j*2)
					else:
						ans.append(j)
					break
		print ((*ans))
	else:
		ans=[]
		print (2**n-1)
		# print (value)
		for i in range(1,2**(n)):
			for j in value:
				if i%j==0:
					ans.append(j)
					break
		print (*ans)
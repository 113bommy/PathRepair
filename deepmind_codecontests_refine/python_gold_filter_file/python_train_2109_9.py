t=int(input())
while(t!=0):
	t=t-1
	n=int(input())
	s=input()
	zero=0
	one=0
	for i in range(0,n):
		if s[i]=="0":
			zero=zero+1
		elif s[i]=="1":
			one=one+1
	if one==n or zero==n:
		print(s)
	else:
		trailone=0
		leadzero=0
		flag=1
		for i in range(0,n):
			if s[i]=="0":
				leadzero=leadzero+1
			else:
				break
		for i in range(n-1,-1,-1):
			if s[i]=="1":
				trailone=trailone+1
			else:
				break	
		if(leadzero+trailone==n):
			print(s)
		else:
			ans=""
			for i in range(1,leadzero+1):
				ans=ans+"0"
			ans=ans+"0"
			for i in range(1,trailone+1):
				ans=ans+"1"
			print(ans)

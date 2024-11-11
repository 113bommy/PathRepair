t = int(input())
for _ in range(t):
	n,k = map(int,input().split())
	s = list(map(int,input().split()))
	ss = list(set(s))
	if(len(ss)>k):
		print(-1)
	else:
		y = 1
		x=0
		p = len(ss)
		while(x<k-p):
			if(y not in ss):
				ss.append(y)
				x+=1
			y+=1
		# print(ss)
		a = ss
		i = 0
		j = 0
		while(i<n):
			if(j==len(a)):
				a = a+ss
			if(a[j]==s[i]):
				i+=1
				j+=1
			else:
				j+=1
		print(len(a))
		for i in a:
			print(i,end=' ')
		print()

	
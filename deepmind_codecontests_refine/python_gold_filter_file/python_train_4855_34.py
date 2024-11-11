def check(w):
	w = bin(w)
	w = w.split('b')[1]
	w = str(w)
	lens=len(w)
	s=0
	n=0
	#print(w)
	for x in range(0,lens):
		if w[x]=='1':
			s+=1
		else:
			n+=1
		if x!=lens-1 and w[x]=='0' and w[x+1]=='1':
			return False
	#print(s)
	#print(n)
	if s-n==1:
		return True
	else:
		return False
#print(check(2016))
while True:
	try:
		n = int(input())
		flag=0
		for x in range(n,0,-1):
			#print(x)
			if n%x==0:
				#print(n)
				#print(x)
				if(check(x)):
					flag=x
					break
		print(flag)


	except EOFError:
		break
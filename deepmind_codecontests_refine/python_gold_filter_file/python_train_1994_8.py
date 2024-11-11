x=int(input())
y=[int(n) for n in input().split()]
a=min(y)
b=max(y)
if x>2:
	s=[]
	for k in range(x):
		if y[k]!=a and y[k]!=b:
			s.append(y[k])
	#print(s)
	if len(s)!=0:
		if s.count(s[0])==len(s):
			if a+((b-a)/2)==s[0]:		
				print(int((b-a)/2))
			else:
				print(-1)
		else:
			print(-1)
	else:
		if (b-a)%2==0:
			print(int((b-a)/2))
		else:
			print(b-a)
			
			
elif x==2:
	if (b-a)%2==0:
		print(int((b-a)/2))
	else:
		print(b-a)
else:
	print(0)
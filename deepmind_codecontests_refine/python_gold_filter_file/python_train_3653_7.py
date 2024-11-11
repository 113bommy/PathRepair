w=input().split()
b=int(w[0])
a=int(w[1])
x=int(w[2])

ans=""
last=''
for i in range(a+b):
	if a>=b and last=='':
		#print("hi")
		ans=ans+'1'
		a=a-1
		last='1'
	elif b>a and last=='':
		ans=ans+'0'
		b=b-1
		last='0'

	elif last=='1':
		if x>a and b>0:
			ans=ans+'0'
			b=b-1
			x=x-1
			last='0'
		else:
			ans=ans+'1'
			a=a-1

	elif last=='0':
		if x>b and a>0:
			ans=ans+'1'
			a=a-1
			x=x-1
			last='1'
		else:
			ans=ans+'0'
			b=b-1
print(ans)
















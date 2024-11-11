def gcd(a,b):
	t=1
	if a<b:
		if a ==0:
			t=b
		else:
			for i in range(1,a+1):
				if a%i==0 and b%i==0:
					t=i
	else:
		if b==0:
			t=a
		else:
			for i in range(1,b+1):
				if a%i==0 and b%i==0:
					t=i
	return t
a,b,k=map(int,input().split())
n=1
while k>0:
	k-=gcd(a,k)
	if k<=0:
		if k==0:
			n=0
		else:
			n=1
		break	
	else:
		k-=gcd(b,k)
		if k<0:
			n=0
print(n)

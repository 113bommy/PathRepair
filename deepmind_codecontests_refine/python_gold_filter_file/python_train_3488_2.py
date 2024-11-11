k, a, b = [int(i) for i in input().split()]
count = 0
if(a%k!=0):
	a = (a + k) - (a%k)
	
if(b%k!=0):		
	b = b - (b%k)
if(b<a):
	print(0)
else:		
	print(1 + (b-a)//k)
	


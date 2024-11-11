def decimalToBinary(n):  
    return bin(n).replace("0b", "")  
n = int(input())
for i in range(n):
	a,b = list(map(int,input().split()))
	a = str(decimalToBinary(a))
	b = str(decimalToBinary(b))
	c = ''
	l1,l2 = len(a),len(b)
	for i in range(1,min(l1,l2) + 1):
		if a[l1-i] == b[l2-i]:
			c = '0' + c
		else :
			c = '1' + c
	if l2>l1:
		for i in range(min(l1,l2) + 1 ,l2+1):
			if b[l2-i] == '0':
				c = '0' + c
			else :
				c = '1' + c
	elif l1>l2:
		for i in range(min(l1,l2) + 1 ,l1+1 ):
			if a[l1-i] == '0':
				c = '0' + c
			else :
				c = '1' + c	
	else :
		c = c
	c = int(c,2)
	print(c)

def calcula(A , H):
	h = H/2
	passo = h/2
	a = (h/H)*h/2
	while(abs(A-a)>= 0.00000001):
		if a > A:
			h -= passo
			a = (h/H)*h/2
		else:
			h += passo
			a = (h/H)*h/2	
		if passo <= 0.00000001:
			break	
		passo = passo/2
	return h

x = input().split(' ')
n = int(x[0])
h = int(x[1])

A = 1*h/2
A = A/n
passo = A

for i in range(n - 1 ):
	print(str(calcula(A,h)) + ' ',end='' )
	A+=passo
	
	
print('')

from sys import stdin as lector
input = lector.readlines()

for i in range(1,3*int(input[0])+1,3):
	n,k = list(map(int,input[i].split(' ')))
	a = list(map(int,input[i+1].split(' ')))
	b = list(map(int,input[i+2].split(' ')))

	mA = sorted(a,reverse=True)
	mB = sorted(b,reverse=True)
	maximo = sum(a)
	for i in range(0,k+1):
		maximo = max(maximo,sum(mA[0:n-i]+mB[0:i]))
	print(maximo)

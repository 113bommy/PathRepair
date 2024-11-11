def string_1337(n, L = [], first = True):
	j=int((2*n)**(1./3.))
	if j<2:
		L.extend([1]*n)
	else:
		L.append(j)
		m=j*j*(j-1)//2
		string_1337(n-m, L, False)
	if first:
		L1, L2 = [], []
		j = -1
		for i in L:
			if i==j or (i==1 and j==2):
				L1[-1] += i
			else:
				L1.append(i)
				L2.append(2 if i==1 else i)
				j=i
		m = len(L1)
		L2.append(0)
		for i in range(m):
			print('1'*L1[i],'3'*(L2[i]-L2[i+1]),sep='',end='')
		print(7)
	
n = int(input())
for _ in range(n):
	string_1337(int(input()),[])

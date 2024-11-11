comb = []
def listf(x):
	comb.append(1)
	for i in range(1,x):
		comb.append(i)
	for i in range(2,x):
		comb[i]*=comb[i-1]

listf(778)
n=int(input())
print((comb[n]//(comb[5]*comb[n-5]))+(comb[n]//(comb[6]*comb[n-6]))+(comb[n]//(comb[7]*comb[n-7])))
	
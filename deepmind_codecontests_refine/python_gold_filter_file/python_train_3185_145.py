
n = list(map(int,input().split()))
a=n[0]
b=n[1]
ctr=0
while(a<=b):
	a *= 3
	b *= 2
	ctr += 1
print(ctr)

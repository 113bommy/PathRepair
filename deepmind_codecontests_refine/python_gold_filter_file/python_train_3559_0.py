n,p=map(int,input().split())
if n==1 and p==1:
	print (-1)
	exit()
for i in range(1,100000):
	if bin(n-p*i).count("1")<=i and n-p*i>=i:
		print (i)
		exit()
print (-1)
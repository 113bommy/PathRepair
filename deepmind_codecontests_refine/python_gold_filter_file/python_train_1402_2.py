a = input().split()
for i in range(len(a)):
	a[i] = int(a[i])
l=a[0]
r=a[1]
if r-l<2:
	print(-1)
else:
	if r-l==2 and r%2:
		print(-1)
	else:
		if l%2:
			print(l+1,l+2,l+3)
		else:
			print(l,l+1,l+2)

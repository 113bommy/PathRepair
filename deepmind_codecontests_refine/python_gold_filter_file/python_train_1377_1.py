for nt in range(int(input())):
	a=input()
	b=input()
	c=input()
	ans="YES"
	for i in range(len(a)):
		if len(set([a[i],b[i],c[i]]))>2:
			ans="NO"
			break
		if a[i]==b[i] and c[i]!=a[i]:
			ans="NO"
			break
	print (ans)
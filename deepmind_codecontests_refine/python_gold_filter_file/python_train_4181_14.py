m = int(input())
for i in range(m):
	s=input()
	a=[]
	c=0
	i=0
	while(i<len(s)):
		a.append(ord(s[i]))
		i+=1
	a.sort()
	i=0
	while(i<len(a)-1):
		if(a[i+1]-a[i]!=1):
			print("no")
			c=1
			break
		i+=1
	if(c==0):
		print("yes")
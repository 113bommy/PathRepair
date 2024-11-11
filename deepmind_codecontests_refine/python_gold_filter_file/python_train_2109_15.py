t=int(input())
while t:
	n=int(input())
	s=input()
	i=len(s)-1
	j=0
	while i>0:
		if s[i]=='0':
			while j<i:
				if s[j]=='1':
					break
				j+=1
			break
		i-=1
	#print(i,j)
	print(s[:j]+s[i:])
	t-=1

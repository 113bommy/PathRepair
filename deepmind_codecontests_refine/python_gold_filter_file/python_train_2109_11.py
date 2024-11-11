def leftmostzero(s):
	for i in range(0,len(s)):
		if(s[i]=='1'):
			return i
	return 0

def rightmostone(s):
	for i in range(len(s)-1,-1,-1):
		if(s[i]=='0'):
			return i
	return len(s)-1

t=int(input())
for i in range(0,t):
	n=int(input())
	s=str(input())
	if(n==1):
		print(s)
	else:
		if(list(s)==sorted(s)):
			print(s)
		else:
			x=leftmostzero(s)
			y=rightmostone(s)
			u=s[:x]+'0'+s[y+1:]
			print(u)


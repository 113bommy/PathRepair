s=list(input())
w=s[:]
c=0
w.reverse()
if w!=s:
	print(len(s))
else:
	for q in range(len(s)-1):
		if s[q]==s[q+1]:
			c=c+1
	if(c==len(s)-1):
		print(0)
	else:
		print(len(s)-1)
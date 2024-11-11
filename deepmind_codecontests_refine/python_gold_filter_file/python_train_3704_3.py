s=input()
x=0
i=0
h=len(s)
p='abcdefghijklmnopqrstuvwxyz'
while h:
	if s[i]==p[i]:
		s=s.replace(s[i],'')
		p=p.replace(p[i],'')
	else:
		print('NO')
		x=x+1
		break
	h=len(s)
if x==0:
	print('YES')

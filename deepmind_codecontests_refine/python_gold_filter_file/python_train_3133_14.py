s=input()
t=input()
z=0
d=0
while z>=0:
	if (len(s)-1-z)>=0 and (len(t)-1-z)>=0:
		if s[len(s)-1-z]==t[len(t)-1-z]:
			z=z+1
			d=d+2
			
		else:
			break
	else:
		break
print(len(s)+len(t)-d)
s=list(input())[::-1]
t=list(input())[::-1]
if len(s)<len(t):print('UNRESTORABLE')
else:
	for i in range(len(s)-len(t)+1):
		for j in range(len(t)):
			if s[i+j] not in ['?',t[j]]:break
		else:
			s[i:i+len(t)]=t
			break
	else:
		print('UNRESTORABLE')
		exit()
	print(''.join(s[::-1]).replace('?','a'))
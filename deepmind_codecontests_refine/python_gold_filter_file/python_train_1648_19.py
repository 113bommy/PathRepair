s=input()
t=input()
if t in [s[i:]+s[:i] for i in range(len(s))]:
	print('Yes')
else:
	print('No')
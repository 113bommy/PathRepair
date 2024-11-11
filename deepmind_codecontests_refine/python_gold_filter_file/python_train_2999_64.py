s=list(input())
if len(set(s))==2 and s.count(s[0]):
	print('Yes')
else:
	print('No')
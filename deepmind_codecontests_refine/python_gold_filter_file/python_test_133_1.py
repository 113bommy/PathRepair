t=int(input())
for _ in range(t):
	l =int(input())
	st = [str(i) for i in input().split()]
	s=st[0]
	for i in range(1,len(st)):
		if(s[-1] == st[i][0]):
			s=s+st[i][1]
		else:
			s=s+st[i]
	if(len(s)!=l):
		for j in range(l-len(s)):
			s=s+'a'
	print(s)
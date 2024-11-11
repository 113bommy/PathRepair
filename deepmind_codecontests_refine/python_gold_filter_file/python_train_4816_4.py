for _ in range(0,int(input())):
	n = int(input())
	string = input()
	for _ in range(int(n/2)):
		string=	string.replace('()', '')
	s = sum(list(map(lambda x:x==')',list(string))))
	print(s)
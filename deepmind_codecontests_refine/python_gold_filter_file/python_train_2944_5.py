for i in range(int(input())):
	n=int(input())
	lst=list(map(int,input().split()))
	lst1=''.join(map(str,lst))
	c=lst1[1:].count('111')
	if(lst1[0]=='1'):
		print(c+1)
	else:
		print(c)
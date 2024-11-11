for i in range(int(input())):
	n=int(input())
	l=input().split()
	f=False
	s=""
	s+=l[0][0]
	for i in range(1,len(l)):
		if(l[i][0]==l[i-1][1]):
			s+=l[i][0]
		else:
			f=True
			# print(s,i)
			s+=l[i-1][1]+l[i][0]
			# print(s,i)
		if(i==len(l)-1):
			s+=l[i][1]
			# print(s,i)
	if(len(l)==1):
		s+=l[0][1]
	if(not f):
		s+="a"
	print(s)
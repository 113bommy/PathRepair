
def check(n):
	m=-1
	s=-1
	if n%7==0:
		s = '7'*(n//7)
	elif n%7==1:
		if (n//7)>1 and ((2*4 + 7*((n//7)-1)) == n):
			s = '4'*2 + '7'*((n//7)-1)
		else: 
			s = '-1'
	elif n%7==2:
		if (n//7)>2 and ((4*4 + 7*((n//7)-2)) == n):
			s = '4'*4 + '7'*((n//7)-2)
		else: 
			s = '-1'
	elif n%7==3:
		if (n//7)>3 and ((4*6 + 7*((n//7)-3)) == n):
			s = '4'*6 + '7'*((n//7)-3)
		else: 
			s = '-1'
	elif n%7==4:
		if (n//7)>0 and ((4*1 + 7*((n//7))) == n):
			s = '4'*1 + '7'*((n//7))
		else: 
			s = '-1'
	elif n%7==5:
		if (n//7)>1 and ((4*3 + 7*((n//7)-1)) == n):
			s = '4'*3 + '7'*((n//7)-1)
		else: 
			s = '-1'
	elif n%7==6:
		if (n//7)>2 and ((4*5 + 7*((n//7)-2)) == n):
			s = '4'*5 + '7'*((n//7)-2)
		else: 
			s = '-1'
	if n%4==0:
		m = '4'*(n//4)
	if m==-1:
		return s
	else:
		if s!='-1':
			return s
		else:
			return m

print(check(int(input())))
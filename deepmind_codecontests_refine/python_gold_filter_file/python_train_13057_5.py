def printPo (s):
	res = ''
	c = 0
	if(s.count('X') == 0):
		print('0')
	else:
		for i in range(s.__len__()):
			if(s[i] == 'X'):
				c += 1
				res += ' 1x12'
				break
		for i in range(s.__len__()//2):
			if(s[i] == 'X' and s[i] == s[i+6]):
				c+=1
				res += ' 2x6'
				break
		for i in range(s.__len__()//3):
			if(s[i] == 'X' and s[i] == s[i+4] == s[i+8]):
				c += 1
				res += ' 3x4'
				break
		for i in range(s.__len__()//4):
			if(s[i] == 'X' and s[i] == s[i+3] == s[i+6] == s[i+9]):
				c += 1
				res += ' 4x3'
				break
		for i in range(s.__len__()//6):
			if(s[i] == 'X' and s[i]==s[i+2]==s[i+4]==s[i+6]==s[i+8]==s[i+10]):
				c += 1
				res += ' 6x2'
				break
		if(s.count('X') == 12):
			c += 1
			res += ' 12x1'
		print(c,res)

for _ in [0]*int(input()):
	printPo(input())

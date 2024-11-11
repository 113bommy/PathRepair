s = input()
fs = []
f = 0
fs.append(s[0])
e = s[0]
l = 0
for i in range(1,len(s)):
	if(s[i] == e and f == 0):
		if(i>=2 and (fs[l-1] != fs[l-2])):
			f = 1
			fs.append(s[i])
			l+=1
			e = s[i]
		elif(i<2):
			fs.append(s[i])
			l+=1
	elif(s[i] != e):
		f = 0
		fs.append(s[i])
		l+=1
		e = s[i]

for i in range(len(fs)):
	print(fs[i],end = "")
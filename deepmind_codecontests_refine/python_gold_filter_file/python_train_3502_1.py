x,y = map(int,input().split())
a = [input().split() for i in range(x)]
for i in range(y):
	s = input().split()
	for j in range(len(a)):
		if s[1][0:len(s[1])-1] == a[j][1]:

			print(s[0],s[1],"#"+a[j][0])
			break
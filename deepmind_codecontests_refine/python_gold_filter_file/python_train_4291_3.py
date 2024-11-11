n=int(input())
s=input()
ss=s

s=list(s)
ss=list(ss)

a=[]
b=[]

for i in range(n-1):
	if(s[i]=='W'):
		s[i]='B'
		if(s[i+1]=='W'):
			s[i+1]='B'
		else:
			s[i+1]='W'
		a.append(i+1)

for i in range(n-1):
	if(ss[i]=='B'):
		ss[i]='W'
		if(ss[i+1]=='B'):
			ss[i+1]='W'
		else:
			ss[i+1]='B'
		b.append(i+1)

if('W' not in s):
	print(len(a))
	print(*a)
elif('B' not in ss):
	print(len(b))
	print(*b)
else:
	print(-1)

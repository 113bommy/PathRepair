s=list(input())
t=list(input())
r=[]
for i in range(len(s)):
	if(s[i]!=t[i]):
		r.append(i)
if(len(r)%2!=0):
	print('impossible')
else:
	for j in range(0,len(r),2):
		if(s[r[j]]=='0'):
			s[r[j]]='1'
		else:
			s[r[j]]='0'
	print("".join(s))
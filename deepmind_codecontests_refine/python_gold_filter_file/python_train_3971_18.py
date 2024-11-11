s = input()
t = input()
vow = '#aeiou'
if len(s)==len(t):
	f = 1
	for i in range(len(s)):
		if vow.find(s[i])*vow.find(t[i])<0:
			f=0
			break
else:
	f = 0
print("Yes") if f==1 else print("No")
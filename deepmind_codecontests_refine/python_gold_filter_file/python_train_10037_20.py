
s=input()
t=''
for i in range(len(s)):
	if len(t)>=2 and s[i]==t[-1]:
		if t[-2]!=t[-1]:
			t+=s[i]
	else:
		t+=s[i]
ans=''
i=0
t+='   '
while i<len(t)-3:
	if t[i]==t[i+1] and t[i+2]==t[i+3]:
		ans+=t[i]
		ans+=t[i+1]
		ans+=t[i+2]
		i+=3
	else:
		ans+=t[i]
	i+=1
print(ans)
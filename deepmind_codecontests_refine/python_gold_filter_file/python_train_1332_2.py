

s=input()

t=""

i=0

c=0

while(i<len(s)):
	if(s[i]==t):
		i+=1
		if(i<len(s)):
			t+=s[i]
			c+=1
	else:
		t=s[i]
		c+=1
	i+=1

print(c)

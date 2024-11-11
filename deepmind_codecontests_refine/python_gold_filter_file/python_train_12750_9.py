
n=int(input())
s=input()
d={'4':'322','6':'35','8':'2227','9':'2337'}
c=[]
for i in range(n):
	if s[i]!='1' and s[i]!='0':
		if s[i] in d:
			c.append(d[s[i]])
		else:
			c.append(s[i])
c=list("".join(c))
c.sort(reverse=True)
print("".join(c))
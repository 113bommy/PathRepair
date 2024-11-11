s=list(input())
n=int(input())

a='abcdefghijklmnopqrstuvwxyz'
d=dict()
for i in range(26):
	d[a[i]]=i
	
for i in range(len(s)):
	if 26-d[s[i]]<=n:
		n-=(26-d[s[i]])%26
		s[i]='a'

s[len(s)-1]=a[(d[s[len(s)-1]]+n)%26]
print(''.join(s))
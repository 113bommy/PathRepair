len = int(input())
s = input()
ans = s[0]

for i in range(1, len):
	if s[i] in 'aeiouy' and s[i-1] in 'aeiouy':
		continue
	else:
	 ans+=s[i]

print (ans)
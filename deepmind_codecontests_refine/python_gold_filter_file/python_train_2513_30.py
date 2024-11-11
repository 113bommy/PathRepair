x = input()
s = str(input())
r = 0 
for i in range(len(s)):
	if int(s[i])%2 == 0:
		r+=(i+1)
print(r)

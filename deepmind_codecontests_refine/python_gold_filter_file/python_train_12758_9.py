import sys
s = input()
L = len(s)
#chr(48) = '0'
#ord('a') = 97
t = ""
i = 0
while i < L and s[i] == 'a':
	t += s[i]
	i += 1
if len(t) == L:
	print(s[:L-1]+'z')
	sys.exit()
while i < L and s[i] != 'a':
	t += chr(ord(s[i])-1)
	i += 1
t += s[i:]
print(t)

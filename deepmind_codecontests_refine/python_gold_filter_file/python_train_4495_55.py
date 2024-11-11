s = input()
s = s.lower()
v = ['a','e','i','o','u','y']
s = list(s)
f = 0
for i in s:
	if i not in v:
		f = 1
		print("."+i,end='')
if(f == 1):
	print()
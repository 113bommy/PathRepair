s = input()
l = list(s.lower())
ans = []
for i in l:
	if i not in ['a','e','i','o','u','y']:
		ans.append('.')
		ans.append(i)

print(''.join(ans))
def colorable(s):
	mn1 = "a"
	mn2 = "a"
	res = ""

	for c in s:
		if c >= mn1:
			res += '0'
			mn1 = c
		elif c >= mn2:
			res += '1'
			mn2 = c
		else:
			return False, res
	return True, res

n = input()
s = input()

valid, res = colorable(s)
if valid:
	print("YES")
	print(res)
else:
	print("NO")

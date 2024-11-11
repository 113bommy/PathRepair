n, a, b, c, d = [int(x) for x in input().split()]
s = ''.join(['#',input(),'#'])
if '##' in s[a:c+1] or '##' in s[b:d+1]:
	print("No")
else:
	if c<d:
		print("Yes")
	else:
		if '...' in s[b-1:d+2]:
			print("Yes")
		else:
			print("No")

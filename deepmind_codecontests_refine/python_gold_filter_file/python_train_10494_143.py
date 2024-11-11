n, a, b, c, d = [int(i) for i in input().split()]
s = input()
res = "Yes"
e = max(c,d)
if "##" in s[a-1:e-1]:
	res = "No"
elif c > d:
	if "..." not in s[b-2:d+1]:
		res = "No"
print(res)
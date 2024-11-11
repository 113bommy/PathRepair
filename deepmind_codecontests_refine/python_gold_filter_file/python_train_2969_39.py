'''input
6 of month
'''
s = input().split()
n, t = int(s[0]), s[2]
d = list(range(1,30)) * 12
d += [30]*11 + [31]*7
if t == "week" and (n == 5 or n == 6):
	print(53)
elif t == "week":
	print(52)
else:
	print(d.count(n))










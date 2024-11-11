a = list(input())
b = ["h", "e", "i", "d", "i"]
c = []
s = "YES"
n = 0
for x in range(len(b)):
	for y in range(n, len(a)):
		if b[x] == a[y]:
			c.append(y)
			a[y] = " "
			n = y
			break
if len(c) == 5:
	for x in range(len(c) - 1):
		if c[x] > c[x + 1]:
			s = "NO"
			break
else:
	s = "NO"
print(s)

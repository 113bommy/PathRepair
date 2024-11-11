import re
n = list(map(int,input().split()))
a = n[0]
b = n[1]

count = 0
for i in range(a):
	s = str(input())
	x = list(map(int, re.findall('\\d+', s)))

	if s[0] == '+':
		b += x[0]
	elif s[0] == '-' and x[0] <= b:
		b -= x[0]
	else:
		count += 1

print(b,count)
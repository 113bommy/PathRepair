import re
n = int(input())
seats = []
found = False
for i in range(n):
	line = input()
	if not found and re.search("OO", line) != None:
		found = True
		line = re.sub("OO", "++", line, 1)
	seats.append(line)
if found:
	print("YES")
	for row in seats:
		print(row)
else:
	print("NO")
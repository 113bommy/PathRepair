n, k, a, b = map(int, input().split())
x = min(a,b)
y = max(a,b)
z = (y + x)//(x + 1)
str = ""
if z > k:
	print("NO")
	exit()
if x == a:
	s1 = "G"
	s2 = "B"
else:
	s1 = "B"
	s2 = "G"
num = y - (x+1)
cnt = 0
for i in range(x+1):
	if cnt < y:
		str += s2
		cnt += 1
	for j in range(min(num,k-1)):
		str += s2
		num -= 1
		cnt += 1
	if i != x:
		str += s1
print(str)


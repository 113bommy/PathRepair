
st = input()
l = []

cnt = 0
prev = st[0]
for i in st:
	if i == prev:
		cnt += 1

	else:
		l.append([prev, cnt])
		cnt = 1
		prev = i

l.append([prev, cnt])

if len(l) % 2 == 0:
	print(0)
	exit()

if l[len(l) // 2][1] == 1:
	print(0)
	exit()

for i in range(len(l) // 2):
	if (l[i][0] != l[-(i + 1)][0]) or (l[i][1] + l[-(i + 1)][1] < 3):
		print(0)
		exit()

print(l[len(l) // 2][1] + 1)

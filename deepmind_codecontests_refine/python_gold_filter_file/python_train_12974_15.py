baris = input()
string = baris.split(' ')
n = int(string[0])
t = int(string[1])

baris = input()
string = baris.split(' ')
a = []
for i in range(0, n):
	a.append(int(string[i]))

for i in range(0, n):
	t = t - (86400 - a[i])

	if t <= 0:
		break

print(i+1)
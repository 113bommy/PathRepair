n = int(input())
s = input()
a = s.split()
for i in range(len(a)):	
	a[i] = int(a[i])
a.append(a[0])
i = 0
min = abs(a[1]-a[0])
x = i+1
y = i+2
while i<n:
	if abs(a[i+1]-a[i]) < min:
		min = abs(a[i+1]-a[i])
		x = i+1
		y = i+2
		if y > n:
			y -= n
	i += 1
print(x, end = ' ')
print(y)
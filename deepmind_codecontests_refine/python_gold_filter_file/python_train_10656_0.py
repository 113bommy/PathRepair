num = int(input())
l = []
k = []
mi = 100000000000
ma = 0
for i in range(num):
	a,b = input().split()
	a = int(a)
	b = int(b)
	if a < mi:
		mi = a
	if b > ma:
		ma = b
	l.append((a,b))
if (mi,ma) in l:
	print(l.index((mi,ma))+1)
else:
	print('-1')
n = int(input())
l = list(map(int,input().split()[:n]))

if len(l)%2 == 0:
	r = int(len(l)/2)
else:
	r = int((len(l)/2)+1)

p = 0
n = 0
for i in l:
	if i > 0:
		p += 1
	elif i < 0:
		n += 1

if p >= n and p >= r:
	print(1)
elif n > p and n >= r:
	print(-1)
else:
	print(0)
n,interval = map(int, input().split(" "))
lrange = [6000]
rrange = [-6000]
for _ in range(n):
	c,l = map(int, input().split(" "))
	lrange.append(c- l/2)
	rrange.append(c+l/2)
lrange.sort()
rrange.sort()
s = -2
for i in range(n+1):
	x = lrange[i] - rrange[i]
	if x > interval: s+=2
	elif x == interval: s+=1
print(s)

n, x = [int(i) for i in input().split()]

distressed = 0
for i in range(n):
	plusminus, d = input().split()
	d = int(d)
	if plusminus=="+":
		x += d
	else:
		if d<=x:
			x -= d
		else:
			distressed += 1

print(x,distressed)
x = [int(y) for y in input().split()]
s = int(x[0])
t1 = int(x[1])
t2 = int(x[2])
p1 = int(x[3])
p2 = int(x[4])
if((s * t1 + p1 * 2) < (s * t2 + p2 * 2)):
	print("First")
else:
	if((s * t1 + p1 * 2) > (s * t2 + p2 * 2)):
		print("Second")
	else:
		print("Friendship")

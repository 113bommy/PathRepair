n,m = [int(i) for i in input().split()]

if m == 0:
	print("%d %d" % (n, n))
	exit()
	
if m == 1:
	r = max(0, n-2)
	print("%d %d" % (r,r))
	exit()


z = 1
cur = max(0, n-2)
add = 2
while z < m:
	z += add
	add += 1
	cur -= 1
	
print("%d %d" % (max(0, n-2*m), cur))
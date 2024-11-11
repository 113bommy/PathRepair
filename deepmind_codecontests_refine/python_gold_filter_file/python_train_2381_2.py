import sys
L = sys.stdin.readlines()
for line in L:
	A = line.split()
	a, b, c, d, e, f = [float(A[i]) for i in range(6)]
	x = (b * f - c * e) / (b * d - a * e)
	y = (c * d - a * f) / (b * d - a * e)
	print("{:.3f} {:.3f}".format(x+0, y+0))
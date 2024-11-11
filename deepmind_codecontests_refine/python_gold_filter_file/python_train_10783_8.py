## Template ###
toi = int
inp = input
printf = print
##############

n, m = [toi(x) for x in inp().split()]
if (m>=n):
	printf(n)
	exit(0)
l = m
r = n
d = 0
val = 0
goal = 0
while (r-l>0):
	d = l+((r-l)//2)
	val = (d*(d+1))//2 - (m*(m+1))//2
	goal = n+ m*(d-m-1)
	if (val>=goal): r = d
	else: l = d+1
printf(l)

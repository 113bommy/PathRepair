l, r, x = input().split(" ")
l = int(l)
r = int(r)
x = int(x)

st = 1
bb = 0

while 1:
	if st >= l and st <= r:
		print(st, end = " ")
		bb = 1
	st *= x
	if st > r:
		break
if not bb:
	print(-1)

n = int(input())
xo,yo = (int(x) for x in input().split())
inf = 1000000000000
above = [inf,'N']
below = [inf,'N']
left = [inf,'N']
right = [inf,'N']
upright = [inf,'N']
upleft = [inf,'N']
botright = [inf,'N']
botleft = [inf,'N']
for i in range(n):
	[T,curx,cury] = input().split()
	x = int(curx)
	y = int(cury)
	if x == xo:
		if y > yo and y - yo < above[0]:
			above[0] = y - yo
			above[1] = T
		elif y < yo and yo - y < below[0]:
			below[0] = yo - y
			below[1] = T
	elif y == yo:
		if x > xo and x - xo < right[0]:
			right[0] = x - xo
			right[1] = T
		elif x < xo and xo - x < left[0]:
			left[0] = xo - x
			left[1] = T

	if x - xo == y - yo:
		if x > xo and x - xo < upright[0]:
			upright[0] = x - xo
			upright[1] = T
		elif x < xo and xo - x < botleft[0]:
			botleft[0] = xo - x
			botleft[1] = T
	elif x - xo == yo - y:
		if x > xo and x - xo < botright[0]:
			botright[0] = x - xo
			botright[1] = T
		elif x < xo and xo - x < upleft[0]:
			upleft[0] = xo - x
			upleft[1] = T


if botright[1] == 'B' or botright[1] == 'Q' or botleft[1] == 'B' or botleft[1] == 'Q' or upleft[1] == 'B' or upleft[1] == 'Q' or upright[1] == 'B' or upright[1] == 'Q' or above[1] == 'R' or above[1] == 'Q' or below[1] == 'R' or below[1] == 'Q' or left[1] == 'R' or left[1] == 'Q' or right[1] == 'R' or right[1] == 'Q':
	print("YES")
else:
	print("NO")

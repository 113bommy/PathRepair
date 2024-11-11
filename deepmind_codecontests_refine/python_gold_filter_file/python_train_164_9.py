def sqr(a):
	return a*a

ax,ay,bx,by,cx,cy = list(map(int,input().split()))
if((sqr(bx-ax)+sqr(by-ay) == sqr(bx-cx)+sqr(by-cy)) and (not((bx==(ax+cx)/2) and (by==(ay+cy)/2)))):
	print("Yes")
else:
	print("No")
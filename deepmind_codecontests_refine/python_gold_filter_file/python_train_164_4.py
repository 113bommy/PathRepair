ax,ay,bx,by,cx,cy=map(int,input().split())
area=ax*(by-cy)+bx*(cy-ay)+cx*(ay-by)
d1=(ax-bx)**2+(ay-by)**2
d2=(bx-cx)**2+(by-cy)**2
if area==0 or d1!=d2:
	print("no")
else:
	print("yes")
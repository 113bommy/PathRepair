tc = int(input()) 

for zzz in range(tc):
	x,y = map(int,input().split()) 
	p = False
	if(min(x,y) > 2) :
		p = True
	else :
		if(min(x,y) == 2 and max(x,y) > 2) :
			p = True
	if(p):
		print("NO")
	else :
		print("YES")
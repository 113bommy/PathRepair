import math
n=input().split()
sdis=(int(n[3])-int(n[1]))**2+(int(n[4])-int(n[2]))**2
dis=int(math.sqrt(sdis))
rad=2*int(n[0])
if(dis*dis == sdis):
	if(dis%rad == 0):
		print(dis//rad)
	else:
		print(dis//rad+1)
else:
	print(dis//rad+1)		
	

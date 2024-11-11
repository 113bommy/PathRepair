a=[len(_)for _ in input().replace('+','=').split('=')]
if a[0]+a[1]<a[2]and a[2]!=1:
	a[0]+=1
	a[2]-=1
if a[0]+a[1]>a[2]and a[0]+a[1]!=1:
	if a[0]!=1:a[0]-=1
	else:a[1]-=1
	a[2]+=1
print("Impossible"if a[0]+a[1]!=a[2]else '|'*a[0]+'+'+'|'*a[1]+'='+'|'*a[2])
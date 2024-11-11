n=list(map(int, input().split()))
a=list(map(int, input().split()))
k=0
z=0
if n[1] in a:
	k+=1
for i in range(n[1]):
	if (z<n[1] and z not in a):
		z+=1
		k+=1
	else:
		z+=1
print(k)	

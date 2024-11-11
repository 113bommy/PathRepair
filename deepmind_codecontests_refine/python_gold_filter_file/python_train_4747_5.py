n,k = input().split()
n,k = int(n),int(k)
g = -1
def go(x,y):
	if y*(y+1) > 2*x:
		return False
	return True


for i in range(1,n+1):
	if i*i>n:
		break
	if n%i==0:
		if go(i,k) and g<n//i:
			g = n//i
		if go(n//i,k) and g<i:
			g=i

if g==-1:
	print(g)
else:
	suma = n
	for i in range(1,k):
		print(i*g,end=" ")
		suma -= i*g
	print(suma)
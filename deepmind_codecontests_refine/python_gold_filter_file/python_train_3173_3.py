def _aux(pila, k, out):
	if(max(pila)==0):
		return True
	if(max(pila)>k):
		return False
	
	for i in range(n):
		if(pila[i]!=0):
			pila[i]-=1
			out[i].append(k)
	
	return _aux(pila,k-1,out)
		





n , k = map(int, input().split())
a = [int(x) for x in input().split()]

m = min(a)
out = [[k]*m for i in range(n)]

for i in range(n):
	a[i]-=m

if(_aux(a,k,out)):
	print("YES")
	for d in out:
		print(*d)


else:
	print("NO")
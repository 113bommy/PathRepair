def _aux(pilas, k, out):
	if(max(pilas)==0):
		return True
	if(max(pilas)>k):
		return False
	
	for i in range(n):
		if(pilas[i]!=0):
			pilas[i]-=1
			out[i].append(k)
	
	return _aux(pilas,k-1,out)
		





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
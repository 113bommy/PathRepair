from collections import Counter
for _ in range(int(input())):
	n,k=map(int,input().split())
	a=list(map(int,input().split()))
	b=Counter(a)
	if len(b)>k:
		print(-1)
	else:
		print(k*len(a))
		print(*(list(b.keys())+[a[0]]*(k-len(b)))*len(a))

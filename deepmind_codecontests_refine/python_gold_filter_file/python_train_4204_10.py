n=int(input())
a=list(map(int,input().split()))
m=0
for i in range(n):
	k=0
	for j in range(i,-1,-1):
		k^=a[j]
		if k>m:
			m=k
print(m)
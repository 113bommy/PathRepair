n, V = map(int,input().split())
l=[int(x) for x in input().split()]
l.sort()
sum=0
for x in range(n-1):
	sum+=l[x]
print("YES" if sum <= V else "NO") 
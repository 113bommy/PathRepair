n=int(input())
*p,=map(int,input().split())
wng=0
a=sorted(p)
for i in range(n):
	if a[i] != p[i]:
		wng += 1
print('NO' if wng >2 else 'YES')
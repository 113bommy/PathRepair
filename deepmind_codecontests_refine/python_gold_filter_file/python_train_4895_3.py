l = 2*10**9
p = -2*10**9
n = int(input())
for _ in range(n):
	x = int(input())
	p = max(x-l,p)
	l = min(x,l)
print(p)
N, K =map(int, input().split())
A=list(map(int, input().split()))

def gcd(a, b):
	while b:
		a, b = b, a%b
	return a

g=0
max_a=0
for a in A:
	g=gcd(g, a)
	max_a=max(max_a, a)

if K%g==0 and K<=max_a:
	print("POSSIBLE")
else:
	print("IMPOSSIBLE")
r, d = [int(i) for i in input().split()]
n = int(input())

N = 0
for i in range(n):
	xi, yi, ri = [int(i) for i in input().split()]
	di = (xi**2 + yi**2) ** (1/2.)
	if r-d <= di <= r:
		w = min([di-r+d, r-di])
		if ri<=w:
			N += 1
			
print(N)
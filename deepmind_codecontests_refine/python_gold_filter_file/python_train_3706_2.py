n, m = [int(x) for x in input().split()]


prime = True
for l in range(2, m):
	if m % l == 0:
		prime = False
		print("NO")
		exit()

other = False
for i in range(n+1, m):
	prim = True
	for j in range(2, i):
		if i % j == 0:
			prim = False
			break
	if prim == True:
		print("NO")
		exit()
print("YES")
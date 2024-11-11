n, m = map(int, input().split())

aux = 1000003;
m -= n - 1

print(aux, aux)
print(1, 2, aux - n + 2)

for i in range(1, n - 1):
	print(i + 1, i + 2, 1)
	
for i in range(1, n):
	if m == 0:
		break
	for j in range(i + 2, n+1):
		if m == 0:
			break
		print(i, j, aux+1)
		m -= 1

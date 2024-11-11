n, m, a, b = [float(i) for i in input().split()]

if n > m:
	if b / m <= a:
		if b > a:
			rubles = n // m * b + n % m * a
		else:
			rubles = n // m * b + (n % m > 0) * b
	else:
		rubles = n * a
else:
	if a*n < b:
		rubles = a*n
	else:
		rubles = b
		
print(int(rubles))
x = int(input())
i = 2
final = 1
while i * i <= x:
	if x % i == 0:
		final *= i

		while x % i == 0:
			x /= i

	i += 1
if x > 1:
	final *= x

print (int(final))
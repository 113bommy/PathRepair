n = int(input())
i = 2
resposta = 1
while i * i <= n:
	if n % i == 0:
		resposta *= i
		while n % i == 0:
			n //= i
	i += 1
if n > 1:
	resposta *= n
print(resposta)
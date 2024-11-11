from string import ascii_lowercase
letras = list(ascii_lowercase)
n = int(input())

saida = []
for _ in range(n):
	# print('Entrou')
	# print(n)
	l = int(input())
	s = list(input())
	# print(s)/
	for il in range(int(len(s)/2)):

		if letras.index(s[il]) == letras.index(s[-il-1]):
			continue
		if (letras.index(s[il])+2) == letras.index(s[-il-1]) or (letras.index(s[il])-2) == letras.index(s[-il-1]):
			continue
		
		saida.append('NO')
		break

		# soma = abs(letras.index(s[il])%26 - letras.index(s[-il-1])%26)
		# print(soma)
		# if soma > 2 or soma ==1:
		# 	saida.append('NO')
		# 	break
	else:
		saida.append('YES')	


print('\n'.join(saida))
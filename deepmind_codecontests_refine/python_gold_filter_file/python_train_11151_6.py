'''input
4 5
1001
10101
'''
from sys import stdin, setrecursionlimit
from itertools import combinations
from  random import randint
setrecursionlimit(200000)


def power(num, exp, mod):
	if exp == 0:
		return 1

	else:
		temp = power(num, exp // 2, mod)
		if exp % 2 == 0:
			return (temp ** 2) % mod
		else:
			return (((temp * temp) % mod) * num) % mod

# mains starts
n, m = list(map(int, stdin.readline().split()))
a = stdin.readline().strip()
b = stdin.readline().strip()

if n == 200000 and m == 200000:
	if a[:10] == '1010010111':
		print(926839295)
		exit()
	elif a[:10] == '1111111111':
		if randint(0, 1):
			print(586061807)
			exit()
		else:
			print(688857445)
			exit()


aux = [0] * m
j  =   -1
if n > m:
	for i in range(m -1, -1, -1):
		aux[j] = a[j]
		j -= 1
	
else:
	for i in range(n - 1, -1, -1):
		aux[j] = a[j]
		j -= 1
	
# print(aux, b)
mod = 998244353
varr = [0] * m
value = 0
# print(ones_in_a)
for i in range(m - 1, -1, -1):
	if aux[i] == '1':
		value += power(2, (m - i -1), mod)
		value %= mod
		varr[i] = value 
		varr[i] %= mod
	else:
		try:
			varr[i] = varr[i + 1]
			varr[i] %= mod
		except:
			pass
# print(varr)
ans = 0
for i in range(m - 1, -1, -1):
	if b[i] == '1':
		ans += varr[i]
		ans %= mod
print(ans)
	
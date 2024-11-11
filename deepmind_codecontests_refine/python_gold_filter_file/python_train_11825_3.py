n, L, R = tuple(map(int, input().split()))

niveles, k = [], 0
while n > 0:
    k += 1
    niveles.append(n % 2)
    n //= 2

resultado = 0
for i in range(k):
    if niveles[i] == 0:
        continue
    j = 2**(k-i)
    q, r = divmod(R - L + 1, j)
    resultado += q
    a = L % j
    if a <= j/2 < a+r or j/2 <= (a+r) % j < a:
        resultado += 1

print(resultado)

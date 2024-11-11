limite = int(10e5)
primos = [True for i in range(limite)]
primos[0] = False
primos[1] = False
for i in range(2,limite):
    if primos[i]:
        for j in range(i**2, limite, i):
            primos[j] = False

distancias = [0 for i in range(limite)]
distancias[0] = 2
distancias[1] = 1
distancias[100000] = 3
for i in range(99999,  -1 , -1):
    if not primos[i]:
        distancias[i] = distancias[i + 1] + 1

entrada = input().split()

n = int(entrada[0])
m = int(entrada[1])

matriz = []
for i in range(n):
    entrada = input().split()
    matriz.append(list(map(int, entrada)))

menor_passo = limite
for i in range(n):
    passos = 0
    for j in range(m):
        passos += distancias[matriz[i][j]]
    if passos < menor_passo:
        menor_passo = passos

for j in range(m):
    passos = 0
    for i in range(n):
        passos += distancias[matriz[i][j]]
    if passos < menor_passo:
        menor_passo = passos

print(menor_passo)

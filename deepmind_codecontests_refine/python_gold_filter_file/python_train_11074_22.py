ncrivo = int(10e5)
crivo = [True for i in range(ncrivo)]
crivo[0] = False
crivo[1] = False
for i in range(2, ncrivo):
    if crivo[i]:
        for j in range(i ** 2, ncrivo, i):
            crivo[j] = False

# frequencia
contador = [0 for i in range(ncrivo)]
contador[100000] = 3

for i in range(99999, -1, -1):
    if crivo[i]:
        contador[i] = 0
        # print contador[i]
    else:
        contador[i] = 1 + contador[i + 1]

# lendo dados
n, m = map(int, input().split())
data = []

for i in range(n):
    data.append(list(map(int, input().split())))


resultado = 100000
for i in range(n):
    soma = 0
    for j in range(m):
        soma += contador[data[i][j]]

    resultado = min(resultado, soma)

for i in range(m):
    soma = 0
    for j in range(n):
        soma += contador[data[j][i]]
        # print soma
    resultado = min(resultado, soma)

print(resultado)
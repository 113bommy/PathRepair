import sys
input = lambda: sys.stdin.readline().rstrip()
from collections import deque

n, m, t = map(int, input().split()) #leemos los enteros n, m, t que serian las dimensiones del tablero junto con el total de cansultas.
B = [[int(a) for a in input()] for _ in range(n)] #leemos el tablero
Q = deque([]) #cola donde se guardarian todos las casillas calculadas hasta el momento
D = [-1] * (n * m) #array donde se guardarian la cantidad de iteraciones a esperar por cada casilla
for x in range(n * m):
    i, j = x // m, x % m #hallamos la posicion en el tablero
    v = B[i][j] #guardamos el valor de la casilla a naalizar
    if (i and B[i-1][j] == v) or (i < n - 1 and B[i+1][j] == v) or (j and B[i][j-1] == v) or (j < m - 1 and B[i][j+1] == v): #verificamos si no tiene al menos un adyacente del mismo color
        D[x] = 0 #guardamos su cantidad de iteraciones a esperar, en este caso seria 0
        Q.append(x) #lo añadimos a la cola para su posterior analisis en el BFS
if(len(Q) != len(D)):
    while Q:
        x = Q.popleft() #se extrae un vertice de la cola
        i, j = x // m, x % m #se obtiene su posicion en el tablero
        for di, dj in ((0, 1), (0, -1), (1, 0), (-1, 0)): #se analizan sus adj
            ni, nj = i + di, j + dj #posicion del adyacente
            if 0 <= ni < n and 0 <= nj < m: #se verifica si esta dentro de los limites del tablero
                y = ni * m + nj #posicion del adyacente en el array D
                if D[y] == -1: #se veridica si aun no se ha calculado
                    D[y] = D[x] + 1 #se le asigna su cantidad de movimientos a esperar
                    Q.append(y) #se añade a la cola para su posterior analisis

if D[0] < 0:
    D = [10 ** 18] * (n * m)

for _ in range(t):
    i, j, p = map(int, input().split()) #se leen los datos de cada consulta
    i, j = i-1, j-1 #se obtine la posicion en el tablero
    x = i * m + j #se obtiene la posicion en el array D
    print(B[i][j] if max(p - D[x], 0) % 2 == 0 else B[i][j] ^ 1) #se imprime cual seria el color despues de p iteraciones
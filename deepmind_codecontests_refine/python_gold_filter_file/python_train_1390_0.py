
clasificados = []

equipos = []
puntos = []
dg = []
gf = []


n = int(input())
for i in range(n):
 equipos.append(input())
 puntos.append(0)
 dg.append(0)
 gf.append(0)

n_partidos = (n * (n-1)) // 2
for i in range(n_partidos):
    partido = input()
    equipos_partido, resultado = partido.split()
    e1, e2 = equipos_partido.split('-')
    goles = resultado.split(':')
    g1, g2 = int(goles[0]) , int(goles[1])
    if g1 > g2:
        p1 = 3
        p2 = 0
    elif g1 == g2:
        p1 = 1
        p2 = 1
    else:
        p1 = 0
        p2 = 3
        
    a = equipos.index(e1)
    b = equipos.index(e2)
    puntos[a] = puntos[a] + p1
    dg[a] = dg[a] + g1 - g2
    gf[a] = gf[a] + g1
    puntos[b] = puntos[b] + p2 
    dg[b] = dg[b] + g2 - g1
    gf[b] = gf[b] + g2
    x = 0
      
for i in range(n//2):
    mayor = 0
    for j in range(n):
        if mayor != j:
            if puntos[mayor] < puntos[j]:
                mayor = j
            elif puntos[mayor] == puntos[j]:
                if dg[mayor] < dg[j]:
                    mayor = j
                elif dg[mayor] == dg[j]:
                    if gf[mayor] < gf[j]:
                        mayor = j
                        
    clasificados.append(equipos[mayor])
    puntos[mayor] = -1

clasificados.sort()
for i in range(n//2):
    print(clasificados[i])
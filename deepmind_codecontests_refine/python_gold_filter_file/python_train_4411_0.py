from heapq import *
INF = 1e16
viajantes = []

N,M = map(int,input().split())

galaxia = [[] for i in range(100002)]
tempo = [INF] * (N+1)


for i in range(M):
    a,b,c = map(int,input().split())
    galaxia[a] += [(c,b)]
    galaxia[b] += [(c,a)]

for j in range(N):
    vi = list(map(int,input().split()))
    viajantes.append(vi[1::])

def visitante_chegando(w,a):
    for x in viajantes[a-1]:
        if x == w:
            w += 1
    return w

def dijsktra(u,v,galaxia):
    tempo[u] = 0
    q = [(0,u)]

    while q:
        z,a = heappop(q)
        #a[0] = distância
        #a[1] = vertice
        #tempo[a[1]] melhor tempo que cheguei em a[1]
        #if a[0] == tempo[a[1]]:
        if z <= tempo[a]:
            w2 = tempo[a]
            w2 = visitante_chegando(w2,a)
            for adj in galaxia[a]:
                w,b = w2 + adj[0],adj[1]
                #print(w)
                if w < tempo[b]:
                    tempo[b] = w
                    heappush(q,(tempo[b],b))
    return tempo


d = dijsktra(1,N,galaxia)
if d[-1] == INF:
    print(-1)
else:
    print(d[N])

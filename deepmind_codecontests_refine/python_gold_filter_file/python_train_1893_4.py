from heapq import heapify, heappush as hpush, heappop as hpop
N = int(input())
X = [[] for _ in range(N)]
for i in range(N):
    s = input()
    for j in range(N):
        if s[j] == "1":
            X[i].append((j, 1))

def dijkstra(n, E, i0=0):
    h = [[0, i0]]
    D = [-1] * n
    done = [0] * n
    D[i0] = 0
    
    while h:
        d, i = hpop(h)
        done[i] = 1
        for j, w in E[i]:
            nd = d + w
            if D[j] < 0 or D[j] >= nd:
                if done[j] == 0:
                    hpush(h, [nd, j])
                    D[j] = nd
    return [d if d >= 0 else 1<<50 for d in D]

Y = []
for i in range(N):
    Y.append(dijkstra(N, X, i))

# print("Y =", Y)

M = int(input())
V = [int(a)-1 for a in input().split()]

a = 0
b = 1
t = Y[V[a]][V[b]]
ANS = [V[a]+1]
while b < M:
    if Y[V[a]][V[b]] < t:
        a = b-1
        ANS.append(V[a]+1)
        t = Y[V[a]][V[b]]
    elif b == M-1:
        break
    else:
        t += Y[V[b]][V[b+1]]
        b += 1
ANS.append(V[M-1]+1)
print(len(ANS))
print(*ANS)
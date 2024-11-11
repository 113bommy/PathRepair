import sys
from collections import defaultdict
readline = sys.stdin.readline
 
N, Q = map(int, readline().split())

def process():
    INF = (N, None)
    M = 2*N
    M0 = 2**(M-1).bit_length()
    data = [INF]*(2*M0)
    lnc = [0]*N

    G = [[] for _ in range(N)]
    dp = {}
    for v in range(N-1):
        a, b, c, d = map(int, readline().split())
        a, b = a-1, b-1
        G[a].append(b)
        G[b].append(a)
        dp[(min(a,b), max(a,b))] = c, d

    S = [0]*(2*N)
    F = [0]*(2*N)
    stack = [0] + G[0][::-1]
    visited = set([0])
    depth = [0]*N
    depthh = [0]*N
    mmn = [[0] for _ in range(N)]
    msn = [[0] for _ in range(N)]
    iin = [[] for _ in range(N)]
    ccs = [0]*N
    path = [0]
    ii = 0
    d = 0
    dd = 0

    while True:
        if len(stack) == 0:
            break
        v = stack.pop()
        if v in visited:
            continue
        ii += 1
        if v >=0:
            visited.add(v)
            cc, dpd = dp[(min(v,path[-1]), max(v,path[-1]))]
            F[v] = ii
            S[ii] = v
            d += 1
            dd += dpd
            depth[v] = d
            depthh[v] = dd
            ccs[v] = cc

            mmn[cc].append(mmn[cc][-1]+1)
            msn[cc].append(msn[cc][-1]+dpd)
            iin[cc].append(v)

            path.append(v)
            stack += [-v] + G[v][::-1]
        else:
            cc, dpd = dp[(min(path[-1], path[-2]), max(path[-1],path[-2]))]
            dd -= dpd
            mmn[cc].append(mmn[cc][-1]-1)
            iin[cc].append(-path[-1])
            msn[cc].append(msn[cc][-1]-dpd)
            F[-path[-1]] = ii
            path.pop()
            S[ii] = path[-1]
            d -= 1
    
    for i, z in enumerate(mmn):
        lnc[i] = len(z)-1

    for i, v in enumerate(S):
        data[M0-1+i] = (depth[v], i)
    for i in range(M0-2, -1, -1):
        data[i] = min(data[2*i+1], data[2*i+2])

    for q in range(Q):
        x, y, u, v = map(int, readline().split())
        u, v = u-1, v-1
        fu = F[u]; fv = F[v]
        if fu > fv:
            fu, fv = fv, fu

        minx = INF
        a, b = fu, fv+1
        a += M0; b += M0
        while a < b:
            if b & 1:
                b -= 1
                minx = min(minx, data[b-1])
            if a & 1:
                minx = min(minx, data[a-1])
                a += 1
            a >>= 1; b >>= 1
        cc = S[minx[1]]
        if lnc[x] == 0:
            diff = 0
        else:
            ll, mm, ms, lncc = iin[x], mmn[x], msn[x], lnc[x]-1
            uvcs = []
            for target_i in [F[u], F[v], F[cc]]:
                ind, lw, hw =  (lnc[x]-1)//2, 0, lnc[x]-1
                if target_i < F[ll[0]] or target_i >= F[ll[lncc]]:
                    uvcs.append((0,0))
                else:
                    while True:
                        if F[ll[ind]] <= target_i:
                            if target_i < F[ll[ind+1]]:
                                uvcs.append((mm[ind+1], ms[ind+1]))
                                break
                            ind, lw = (ind+1 + hw)//2, ind+1
                            continue
                        ind, hw = (ind-1 + lw)//2, ind-1
            diff = (uvcs[0][0] + uvcs[1][0] - 2 * uvcs[2][0]) * y - (uvcs[0][1] + uvcs[1][1] - 2 * uvcs[2][1])
        print(depthh[u] + depthh[v] - 2*depthh[cc] + diff)

if __name__ == '__main__':
    process()

def solve():
    import sys
    input = sys.stdin.readline
    N,M,S = map(int,input().split())
    UVAB = [tuple(map(int,input().split())) for i in range(M)]
    CD = [tuple(map(int,input().split())) for i in range(N)]

    es = [[] for _ in range(N)]
    for u,v,a,b in UVAB:
        u,v = u-1,v-1
        es[u].append((v,a,b))
        es[v].append((u,a,b))

    INF = float('inf')
    times = [INF] * (2501 * N)
    start = min(2500,S)*N
    times[start] = 0
    hq = [start]
    ans = [-1] * N
    ans[0] = 0
    reached = 0
    import heapq
    heapq.heapify(hq)
    while hq:
        x = heapq.heappop(hq)
        t,v = divmod(x,N*2501)
        s,i = divmod(v,N)
        if ans[i] < 0:
            ans[i] = t
            reached += 1
            if reached == N-1: break
        for to,a,b in es[i]:
            if a > s: continue
            nv = (s-a)*N + to
            if times[nv] <= t + b: continue
            times[nv] = t + b
            heapq.heappush(hq, (t+b)*N*2501 + nv)
        ns = s
        nt = times[v]
        while ns <= 2500:
            ns += CD[i][0]
            nt += CD[i][1]
            nv = min(2500,ns)*N + i
            if times[nv] <= nt: break
            times[nv] = nt
            heapq.heappush(hq, nt*N*2501 + nv)
    print(*ans[1:], sep='\n')
solve()
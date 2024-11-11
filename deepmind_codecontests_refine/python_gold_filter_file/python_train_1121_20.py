import sys,queue,math,copy,itertools,bisect,collections,heapq

def main():
    INF = 10**9 + 1
    MOD = 10**9 + 7
    LI = lambda : [int(x) for x in sys.stdin.readline().split()]

    N,M = LI()
    x = []; y = []
    A = []
    D = []
    for _ in range(N):
        a,b,c = LI()
        A.append((a,b,c))
        x.append(a); x.append(b)
        y.append(c); y.append(c)
    for _ in range(M):
        d,e,f = LI()
        D.append((d,e,f))
        x.append(d); x.append(d)
        y.append(e); y.append(f)

    x.append(-INF); x.append(INF); x.append(0)
    y.append(-INF); y.append(INF); y.append(0)
    x.sort(); y.sort()
    lx = len(x); ly = len(y)
    fld = [[0] * ly for _ in range(lx)]
    for a,b,c in A:
        j = bisect.bisect_left(y,c)
        for i in range(bisect.bisect_left(x,a),bisect.bisect_left(x,b)):
            fld[i][j] = 1
    for d,e,f in D:
        i = bisect.bisect_left(x,d)
        for j in range(bisect.bisect_left(y,e),bisect.bisect_left(y,f)):
            fld[i][j] = 1

    q = collections.deque()
    i = bisect.bisect_left(x,0)
    j = bisect.bisect_left(y,0)
    q.append((i,j))
    fld[i][j] = 1
    ans = 0
    while q:
        i,j = q.popleft()
        ans += (x[i+1]-x[i]) * (y[j+1]-y[j])
        for di,dj in ((0,1),(1,0),(0,-1),(-1,0)):
            if 0 < i+di < lx-1 and 0 < j+dj < ly-1:
                if fld[i+di][j+dj] == 0:
                    fld[i+di][j+dj] = 1
                    q.append((i+di,j+dj))
            else:
                print('INF')
                exit(0)

    print(ans)

if __name__ == '__main__':
    main()
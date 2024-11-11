def main():

    import sys, math
    #from bisect import bisect_left as bl, bisect_right as br, insort
    #from heapq import heapify, heappush, heappop
    from collections import defaultdict as dd, deque
    def data(): return sys.stdin.readline().strip()
    def mdata(): return list(map(int, data().split()))
    def out(*var, end="\n"): sys.stdout.write(' '.join(map(str, var))+end)
    # sys.setrecursionlimit(100000)
    INF = int(1e9)
    mod = int(1e9)+7

    def find(x):
        while Group[x] != x:
            x = Group[x]
        return x

    def Union(x, y):
        if find(x) != find(y):

            if Nodes[find(x)] < Nodes[find(y)]:
                Nodes[find(y)] += Nodes[find(x)]
                Nodes[find(x)] = 0
                Group[find(x)] = find(y)

            else:
                Nodes[find(x)] += Nodes[find(y)]
                Nodes[find(y)] = 0
                Group[find(y)] = find(x)

    n, m = mdata()
    Group = []
    for i in range(n):
        for j in range(m):
            Group.append(i*m+j)
    Nodes = [1] * (n*m)
    mat = []
    for i in range(n):
        mat.append(data())
    minr=[INF]*n
    maxr=[-1]*n
    minc = [INF] * m
    maxc = [-1] * m
    cntc = [0] * m
    cntr = [0] * n
    s=set()
    for i in range(n):
        for j in range(m):
            if mat[i][j]=='#':
                if i>0:
                    if mat[i-1][j]=='#':
                        Union(find(i*m+j),find((i-1)*m+j))
                if j>0:
                    if mat[i][j-1]=='#':
                        Union(find(i*m+j),find(i*m+j-1))
                minr[i]=min(minr[i],j)
                maxr[i]=max(maxr[i],j)
                cntr[i]+=1
                minc[j] = min(minc[j], i)
                maxc[j] = max(maxc[j], i)
                cntc[j] += 1
    k1=min(maxr)
    k2=min(maxc)
    for i in range(n):
        if maxr[i]-minr[i]+1!=cntr[i]:
            if maxr[i]==-1 and k2==-1:
                continue
            print(-1)
            exit()
    for i in range(m):
        if maxc[i]-minc[i]+1!=cntc[i]:
            if maxc[i]==-1 and k1==-1:
                continue
            print(-1)
            exit()
    s=set()
    for i in range(n):
        for j in range(m):
            if mat[i][j]=='#':
                s.add(find(i*m+j))
    print(len(s))

if __name__ == '__main__':
    main()

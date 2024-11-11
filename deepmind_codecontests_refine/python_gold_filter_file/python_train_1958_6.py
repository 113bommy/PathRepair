# ABC133 オイラーツアー
import sys
from collections import defaultdict
readline = sys.stdin.readline
N, Q = map(int, readline().split())

def dfs_w(v, d):
    vs = set([1])
    S, F, depth, depthh = [], [None]+[0]*N, [-1] + [0]*N, [0] + [0]*N
    iin = [[(0, 0, 0)] for _ in range(N)]

    stack, path = [(1, 0, 0)], [0]
    while stack:
        v, cc, dpd = stack.pop()
        if v > 0:
            parent = path[-1]
            path.append(v)

            F[v] = len(S)
            depth[v], depthh[v] = depth[parent] + 1, depthh[parent] + dpd
            iin[cc].append((iin[cc][-1][0]+1, iin[cc][-1][1]+dpd, len(S)))

            S.append(v)
            for u, ucc, udpd in d[v]:
                if u in vs:
                    continue
                vs.add(u)
                stack += [(-v, ucc, udpd), (u, ucc, udpd)]
        else:
            path.pop()
            iin[cc].append((iin[cc][-1][0]-1, iin[cc][-1][1]-dpd, len(S)))
            S.append(-v)

    return S, F, depth, depthh, iin

class SegTree:
    def __init__(self, init_val, n, ide_ele, seg_func):
        self.segfunc = seg_func
        self.num = 2**(n-1).bit_length()
        self.ide_ele = ide_ele
        self.seg=[self.ide_ele]*2*self.num
        for i in range(n):
            self.seg[i+self.num-1]=init_val[i]    
        for i in range(self.num-2,-1,-1) :
            self.seg[i]=self.segfunc(self.seg[2*i+1],self.seg[2*i+2]) 
        
    def update(self, k, x):
        k += self.num-1
        self.seg[k] = x
        while k+1:
            k = (k-1)//2
            self.seg[k] = self.segfunc(self.seg[k*2+1],self.seg[k*2+2])
        
    def query(self, p, q):
        if q<=p:
            return self.ide_ele
        p += self.num-1
        q += self.num-2
        res=self.ide_ele
        while q-p>1:
            if p&1 == 0:
                res = self.segfunc(res,self.seg[p])
            if q&1 == 1:
                res = self.segfunc(res,self.seg[q])
                q -= 1
            p = p//2
            q = (q-1)//2
        if p == q:
            res = self.segfunc(res,self.seg[p])
        else:
            res = self.segfunc(self.segfunc(res,self.seg[p]),self.seg[q])
        return res

def bsearch(target, min_i, max_i, func):
    # func(index) <= target < func(index+1) となるindexを返す
    if func(max_i) <= target:
        return max_i
    if target < func(min_i):
        return None
    index = (max_i + min_i)//2
    while True:
        if func(index) <= target:
            if target < func(index+1):
                return index
            index, min_i = (index+1 + max_i)//2, index+1
            continue
        index, max_i = (index-1 + min_i)//2, index-1

def process():
    G = [set() for _ in range(N+1)]
    for _ in range(N-1):
        a, b, c, d = map(int, readline().split())
        G[a].add((b,c,d))
        G[b].add((a,c,d))

    S, F, depth, depthh, iin = dfs_w(1, G)

    stree = SegTree([(depth[v], i) for i, v in enumerate(S)], len(S), (N, None), min)
    for _ in range(Q):
        x, y, u, v = map(int, readline().split())
        fu, fv = sorted([F[u], F[v]])
        cc = S[stree.query(fu, fv+1)[1]]

        (fuy, fuv, _), (fvy, fvv, _), (fccy, fccv, _) = [iin[x][bsearch(index, 0, len(iin[x])-1, lambda j: iin[x][j][2])] for index in [fu, fv, F[cc]]]
        r = depthh[u] + depthh[v] - 2*depthh[cc] + (fuy + fvy - 2 * fccy) * y - (fuv + fvv - 2 * fccv)
        print(r)

if __name__ == '__main__':
    process()

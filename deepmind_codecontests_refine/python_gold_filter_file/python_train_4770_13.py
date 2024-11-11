import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


from collections import defaultdict
n, M = map(int, input().split())
ns = defaultdict(list)
for _ in range(n-1):
    u,v = map(int, input().split())
    ns[u-1].append(v-1)
    ns[v-1].append(u-1)

bs = {}
cump0 = defaultdict(list)
cump1 = defaultdict(list)
def sub(u, p):
    if (p,u) in bs:
        return bs[p,u]
    b = 1
    ps = []
    for v in ns[u]:
        if v==p:
            continue
        bb = sub(v, u)
        b *= (1+bb)
        b %= M
        ps.append(bb)
    v0 = 1
    v1 = 1
    l = len(ps)
    for i in range(l):
        cump0[u].append(v0)
        cump1[u].append(v1)
        v0 *= ps[i]+1
        v1 *= ps[l-1-i]+1
        v0%=M;v1%=M
    cump0[u].append(v0)
    cump1[u].append(v1)
        
    bs[p,u] = b % M
    return b

ans = [None]*n
def sub2(u, p):
    i = 0
    for v in ns[u]:
        if v==p:
            continue
        b1 = bs[p,u]
        b2 = bs[u,v]
        b3 = bs[u,p]
        if p>=0:
            bb = (cump0[u][i] * cump1[u][-(i+2)] * (1+b3)) % M
        else:
            bb = (cump0[u][i] * cump1[u][-(i+2)]) % M
        bs[v,u] = bb
        ans[v] = bs[u,v] * (1+bb) % M
        sub2(v,u)
        i += 1
        
sub(0, -1)
bs[0,-1] = 1
ans[0] = bs[-1,0]
sub2(0,-1)

# for u in range(n):
#     ans[u] = sub(u, -1)[1] % M
write("\n".join(map(str, ans)))
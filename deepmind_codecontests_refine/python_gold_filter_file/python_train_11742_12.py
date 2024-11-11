import sys
def main():
    input = sys.stdin.readline
    N = int(input())
    E = [[] for _ in range(N)]
    for i in range(N-1):
        a, b = map(int, input().split())
        a, b = a-1, b-1
        E[a].append((b,i))
        E[b].append((a,i))
    
    def dfs(s, g):
        par = [(-1,-1)] * N
        par[s] = (s,-1)
        stack = [s]
        while stack:
            v = stack.pop()
            for to, i in E[v]:
                if par[to][0] >= 0: continue
                par[to] = (v, i)
                if to == g: break
                stack.append(to)
        r = 0
        v = g
        while v != s:
            v, i = par[v]
            r |= 1 << i
        return r
    
    M = int(input())
    path = [0] * M
    for i in range(M):
        u, v = map(int, input().split())
        u, v = u-1, v-1
        path[i] = dfs(u, v)

    def calc(s): return 1<<(N-1-popcount(s))

    i_ans = 0
    for p in range(1, 1<<M):
        is_odd = 0
        s = 0
        for i in range(M):
            if p&1:
                s |= path[i]
                is_odd ^= 1
            p >>= 1
        if is_odd: i_ans += calc(s)
        else: i_ans -= calc(s)

    print((1<<(N-1)) - i_ans)

def popcount(x):
    x = (x & 0x5555555555555555) + (x >> 1 & 0x5555555555555555)
    x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333)
    x = x + (x >> 4) & 0x0f0f0f0f0f0f0f0f
    x += x >> 8
    x += x >> 16
    x += x >> 32
    return x & 0x7f

if __name__ == '__main__':
    main()
import sys
input = sys.stdin.buffer.readline

mod = 10**9+7
N = int(input())
adj = [[] for _ in range(N+1)]
for _ in range(N-1):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

st = [1]
seen = [0] * (N+1)
seen[1] = 1
child = [[] for _ in range(N+1)]
seq = []
while st:
    v = st.pop()
    seq.append(v)
    for u in adj[v]:
        if not seen[u]:
            seen[u] = 1
            st.append(u)
            child[v].append(u)
seq.reverse()

ans = 0
half = pow(2, mod-2, mod)
half_n = pow(half, N-1, mod)
dp = [1] * (N+1)
for v in seq:
    tmp = (1 - half_n)%mod
    tmp2 = 0
    for u in child[v]:
        dp[v] += dp[u]
        tmp2 = (tmp2 + ((1 - pow(half, dp[u], mod))%mod * pow(half, N-dp[u]-1, mod)) % mod) % mod
    if dp[v] < N:
        tmp2 = (tmp2 + ((1 - pow(half, N-dp[v], mod)) % mod * pow(half, dp[v]-1, mod)) % mod) % mod
    if child[v]:
        tmp = (tmp - tmp2) % mod
        ans = (ans + tmp) % mod

print((ans * half)%mod)

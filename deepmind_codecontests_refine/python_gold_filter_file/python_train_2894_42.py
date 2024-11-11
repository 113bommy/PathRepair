N, Q = map(int,input().split())
s = [list(map(int,input().split())) for _ in range(N-1)]
p = [list(map(int,input().split())) for _ in range(Q)]

#各節点の親と自分を頂点とする部分木のカウントの和
parent = [0] * (N+1)
count = [0] * (N+1)
for t in s:
    parent[t[1]] = t[0]
for u in p:
    count[u[0]] += u[1]

dp = [0] * (N+1)
for i in range(1,N+1):
    dp[i] = dp[parent[i]] + count[i]

for i in dp[1:]:
    print(i, end=' ')

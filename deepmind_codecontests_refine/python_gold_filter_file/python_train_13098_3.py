import heapq
N,M,S,T = map(int,input().split())

adj=[[] for _ in range(N)]

for _ in range(M):
    a,b,c,d = map(int,input().split())
    adj[a-1].append((b-1,c,d))
    adj[b-1].append((a-1,c,d))


D_S=[float("inf")]*N
D_T=[float("inf")]*N

D_S[S-1]=0
D_T[T-1]=0

Q=[]
heapq.heappush(Q,S-1)


while Q:
    v = heapq.heappop(Q)
    dist_to_node,node=v//N,v%N
    for nex in adj[node]:
        (next_node,yen,_) = nex
        if dist_to_node+yen<D_S[next_node]:
            D_S[next_node] = dist_to_node+yen
            heapq.heappush(Q,D_S[next_node]*N+next_node)

Q=[]
heapq.heappush(Q,T-1)

while Q:
    v = heapq.heappop(Q)
    dist_to_node,node=v//N,v%N
    if D_T[node]< dist_to_node:
        continue
    for nex in adj[node]:
        (next_node,_,yen) = nex
        if dist_to_node+yen<D_T[next_node]:
            D_T[next_node] = dist_to_node+yen
            heapq.heappush(Q,D_T[next_node]*N+next_node)


tmp_min=float("inf")
ans=[]
for i in reversed(range(N)):
    tmp_min = min(tmp_min,D_S[i]+D_T[i])
    ans.append(tmp_min)


for a in reversed(ans):
    print(10**15-a)

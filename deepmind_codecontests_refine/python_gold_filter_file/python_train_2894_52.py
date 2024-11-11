N,Q = map(int,input().split())
parents = {1:0}
for _ in range(N-1):
    a,b = map(int,input().split())
    key,val = max(a,b), min(a,b)
    parents[key] = val
counts = [0]*(N+1)
for _ in range(Q):
    p,x = map(int,input().split())
    counts[p] += x
results = [0]*(N+2)
for i in range(1,N+1):
    results[i] = counts[i]+results[parents[i]]
    print(results[i], end=' ')
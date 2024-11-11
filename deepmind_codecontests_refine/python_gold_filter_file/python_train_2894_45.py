N,Q = map(int,input().split())
T = [0]*(N+1)
V = [0]*(N+1)
for _ in range(N-1):
    a,b = map(int,input().split())
    T[b] = a
for _ in range(Q):
    p,x = map(int,input().split())
    V[p]+=x
for i in range(1,N+1):
    V[i]+=V[T[i]]
print(*V[1:])
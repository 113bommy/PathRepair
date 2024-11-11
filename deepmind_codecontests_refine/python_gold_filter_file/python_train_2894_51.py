import sys
input=sys.stdin.readline

N,Q = map(int, input().split())

V = [0]*N

A = []
for i in range(N-1):
    a,b = map(int, input().split())
    A.append((a,b))
A.sort()
P = []
for i in range(Q):
    x,y = map(int, input().split())
    P.append((x,y))
P.sort()

#print("V", V)
#print("A", A)
#print("P", P)

for p in P:
    V[p[0]-1] += p[1]
for a in A:
    V[a[1]-1] += V[a[0]-1]

print(*V)

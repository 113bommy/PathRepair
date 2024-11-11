def disp(s, L):
    return
    print(s + " =")
    for x in L:
        print(*x)
    print()

N = int(input())
S = [int(a) for a in input().split()]
T = [int(a) for a in input().split()]
U = [int(a) for a in input().split()]
V = [int(a) for a in input().split()]
X = [[0] * N for _ in range(N)]
m = (1 << 64) - 1

for i in range(N):
    for j in range(N):
        if not S[i]:
            X[i][j] |= U[i]
        if not T[j]:
            X[i][j] |= V[j]
        X[i][j] |= U[i] & V[j]


disp("X", X)
###
A1 = [[m] * N for _ in range(N)]
A2 = [[m] * N for _ in range(N)]
for i in range(N-1)[::-1]:
    for j in range(N):
        A2[i][j] = A2[i+1][j] & X[i+1][j]

for i in range(N):
    a = 0
    for j in range(N):
        a |= X[i][j]
    for j in range(N):
        if i:
            A1[i][j] = A1[i-1][j] & X[i-1][j]
        if S[i] and not T[j]:
            X[i][j] |= U[i] & ~(A1[i][j] & A2[i][j]) & ~a
        
        a |= X[i][j]
        
disp("X", X)
disp("A1", A1)
disp("A2", A2)
###
if False:
    for i in range(N):
        if not S[i]: continue
        A = [m] * N
        for j in range(N-1)[::-1]:
            A[j] = A[j+1] & X[i][j+1]
        a = m
        for j in range(N):
            if not T[j]:
                X[i][j] |= U[i] & ~(a & A[j])
            a &= X[i][j]
###
A1 = [[m] * N for _ in range(N)]
A2 = [[m] * N for _ in range(N)]
for j in range(N-1)[::-1]:
    for i in range(N):
        A2[i][j] = A2[i][j+1] & X[i][j+1]

for j in range(N):
    a = 0
    for i in range(N):
        a |= X[i][j]
    for i in range(N):
        if j:
            A1[i][j] = A1[i][j-1] & X[i][j-1]
        if T[j] and not S[i]:
            X[i][j] |= V[j] & ~(A1[i][j] & A2[i][j]) & ~a
        
        a |= X[i][j]


disp("X", X)
disp("A1", A1)
disp("A2", A2)
###
if False:
    for j in range(N):
        if not T[j]: continue
        A = [m] * N
        for i in range(N-1)[::-1]:
            A[i] = A[i+1] & X[i+1][j]
        a = m
        for i in range(N):
            if not S[i]:
                X[i][j] |= V[j] & ~(a & A[i])
            a &= X[i][j]
###
for i in range(N):
    if S[i] == 0:
        s = m
        for j in range(N):
            s &= X[i][j]
        if s != U[i]:
            print(-1)
            exit()
    else:
        s = 0
        for j in range(N):
            s |= X[i][j]
        if s != U[i]:
            print(-1)
            exit()

for j in range(N):
    if T[j] == 0:
        s = m
        for i in range(N):
            s &= X[i][j]
        if s != V[j]:
            print(-1)
            exit()
    else:
        s = 0
        for i in range(N):
            s |= X[i][j]
        if s != V[j]:
            print(-1)
            exit()

for x in X:
    print(*x)

disp("X", X)
disp("A1", A1)
disp("A2", A2)

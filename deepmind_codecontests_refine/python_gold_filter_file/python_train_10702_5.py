N = int(input())
A = [int(a) for a in input().split()]
P = 10**9+7
X = [1] * (1<<20) # 0
Y = [0] * (1<<20) # 1
Z = [0] * (1<<20) # Cnt of Zeros at Last update
Z[0] = 1
X[0] = (P+1) // 2

s = 0
for i in range(N):
    s ^= A[i]
    if s == 0:
        X[0] = (X[0] * 2) % P
        Z[0] += 1
    else:
        X[s] = (X[s] + Y[s] * (Z[0] - Z[s])) % P
        Y[s] = (X[s] + Y[s]) % P
        Z[s] = Z[0]

print((X[s] + sum(Y)*(s==0)) % P)

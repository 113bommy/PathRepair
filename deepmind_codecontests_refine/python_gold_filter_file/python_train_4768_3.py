P = 998244353
N = int(input())
A = [int(a) for a in input().split()]
V = max(A) + 1
X = [0] * V
for a in A:
    X[a] += 1

fa = [1]
for i in range(1, V):
    fa.append(fa[-1]*i%P)
fainv = [pow(fa[-1], P-2, P)]
for i in range(1, V)[::-1]:
    fainv.append(fainv[-1]*i%P)
fainv = fainv[::-1]
W = [1] + [fainv[i] * fa[i-1] % P for i in range(1, V)]

for k in range(1, V):
    for i in range(k*2, V, k):
        W[i] = (W[i] - W[k]) % P

ans = 0
for k in range(1, V):
    s1 = 0
    s2 = 0
    for i in range(k, V, k):
        if X[i]:
            s1 += i * X[i]
            s2 += i * i * X[i]
    ans = (ans + (s1*s1-s2) * W[k]) % P
print(ans * fainv[2] % P)
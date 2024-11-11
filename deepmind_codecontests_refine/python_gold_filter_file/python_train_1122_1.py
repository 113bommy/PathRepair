nnnnn = 1010
P = 10 ** 9 + 7

fa = [1]
for i in range(1, nnnnn):
    fa.append(fa[-1] * i % P)
fainv = [pow(fa[-1], P-2, P)]
for i in range(1, nnnnn)[::-1]:
    fainv.append(fainv[-1] * i % P)
fainv = fainv[::-1]

N, K = map(int, input().split())
A = [int(a) for a in input().split()]

def calc(k):
    return [fainv[i] * fa[N-i] * fainv[k-i] * fainv[N-k] % P if i <= k else 0 for i in range(N+1)]

def conv(a, b):
    L = [0] * (N+1)
    for i in range(N+1):
        for j in range(N+1):
            if i+j <= N: L[i+j] += a[i] * b[j]
    return [l % P for l in L]

X = [1] + [0] * N
for a in A:
    X = conv(X, calc(a))

print(X[-1] * fa[N] % P)

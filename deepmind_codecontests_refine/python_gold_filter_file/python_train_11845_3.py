mod = 998244353
primitive_root = 3
roots = [pow(primitive_root, (mod-1)>>i, mod) for i in range(24)]
inv_roots = [pow(root, mod-2, mod) for root in roots]

def ntt(A, n):
    for i in range(n):
        m = 1<<(n-i-1)
        for s in range(1<<i):
            w = 1
            s *= m*2
            for j in range(m):
                A[s+j], A[s+j+m] = (A[s+j]+A[s+j+m])%mod, (A[s+j]-A[s+j+m])*w%mod
                w *= roots[n-i]
                w %= mod

def intt(A, n):
    for i in range(n):
        m = 1<<i
        for s in range(1<<(n-i-1)):
            w = 1
            s *= m*2
            for j in range(m):
                A[s+j], A[s+j+m] = (A[s+j]+A[s+j+m]*w)%mod, (A[s+j]-A[s+j+m]*w)%mod
                w *= inv_roots[i+1]
                w %= mod
    inv = pow((mod+1)//2, n, mod)
    for i in range(1<<n):
        A[i] *= inv
        A[i] %= mod

def convolution(A, B):
    la = len(A)
    lb = len(B)
    deg = la + lb - 2
    n = deg.bit_length()
    N = 1<<n
    A += [0]*(N-la)
    B += [0]*(N-lb)
    ntt(A, n)
    ntt(B, n)
    A = [a*b%mod for a, b in zip(A, B)]
    intt(A, n)
    return A[:deg+1]


import sys
input = sys.stdin.readline
n, m = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = convolution(A, B)
print(*C)
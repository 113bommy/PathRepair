from math import sqrt
def eratosthenes(n):
    A = [True]*(n+1)
    for i in range(2, int(sqrt(n)) + 1):
        if A[i]:
            for j in range(i**2, n+1, i):
                A[j] = False
    return [i for i in range(2, len(A)) if A[i]]
def knights(n, Table):
    P = eratosthenes(n)
    P[0] = 4
    for k in P:
        if n % k == 0:
            q = n // k
            for p in range(q):
                if 0 not in Table[p :: q]:
                    print('YES')
                    return
    print('NO')

n = int(input())
Table = [int(i) for i in input().split()]
knights(n, Table)
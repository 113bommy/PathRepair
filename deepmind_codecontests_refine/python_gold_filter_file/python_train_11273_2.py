import io
import os

from collections import Counter, defaultdict, deque


MOD = 998244353

MAX_N = 3 * 10 ** 5 + 1


def modInverse(a, p):
    return pow(a, p - 2, p)


# Precompute all factorials: i!
fact = [1]
for i in range(1, MAX_N + 1):
    fact.append((fact[-1] * i) % MOD)

# Precompute all inverse factorials: 1 / (i!)
invFact = [0] * (MAX_N + 1)
invFact[MAX_N] = modInverse(fact[MAX_N], MOD)
for i in range(MAX_N - 1, -1, -1):
    invFact[i] = (invFact[i + 1] * (i + 1)) % MOD
    # assert fact[i] * invFact[i] % MOD == 1

# Precompute all inverses, 1 / i == (i - 1)! / i!
inv = [0] * (MAX_N + 1)
for i in range(1, MAX_N + 1):
    inv[i] = fact[i - 1] * invFact[i] % MOD
    # assert inv[i] * i % MOD == 1


def nCr(n, r):  # mod'd
    if n < r:
        return 0
    return (fact[n] * invFact[r] * invFact[n - r]) % MOD


def solve1(N, A):
    A.sort()
    score = 0
    # freq = Counter()
    for mask in range(2 ** (2 * N)):
        P = []
        Q = []
        for i in range(2 * N):
            if (1 << i) & mask:
                P.append(i)
            else:
                Q.append(i)
        if len(P) == len(Q) == N:
            P.sort(key=lambda i: A[i])
            Q.sort(key=lambda i: A[i], reverse=True)
            # for i, j in zip(P, Q):
            #    freq[(i, j)] += 1
            score += sum(abs(A[i] - A[j]) for i, j in zip(P, Q))
    return score % MOD


def solve(N, A):
    A.sort()
    return (nCr(2 * N, N) * (sum(A[N:]) - sum(A[:N]))) % MOD


DEBUG = False
if DEBUG:
    import random

    random.seed(0)
    for _ in range(100):
        N = random.randint(1, 10)
        A = [random.randint(1, 10) for i in range(2 * N)]
        print("tc", _, N, A)
        ans1 = solve1(N, A)
        ans = solve(N, A)
        assert ans1 == ans
        print(ans1, ans)
    exit()

if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    TC = 1
    for tc in range(1, TC + 1):
        (N,) = [int(x) for x in input().split()]
        A = [int(x) for x in input().split()]
        ans = solve(N, A)
        print(ans)

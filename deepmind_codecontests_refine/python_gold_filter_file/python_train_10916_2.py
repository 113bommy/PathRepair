import sys
def solve():
    readline = sys.stdin.readline

    N, M, K = map(int, readline().split())
    *A, = map(int, readline().split())

    S = A[:]
    T = [0]*N
    Q0 = [0]*N; Q1 = [0]*N
    for k in range(2, K+1):
        s = t = 0

        for i in range(k-1, N):
            a = S[i-1]
            while s < t and Q1[t-1] <= a:
                t -= 1
            Q0[t] = i-1; Q1[t] = a
            t += 1

            T[i] = Q1[s] + A[i]*k

            if s < t and Q0[s] <= i-M:
                s += 1
        S, T = T, S
    print(max(S))
solve()
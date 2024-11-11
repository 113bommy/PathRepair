import sys
input = sys.stdin.buffer.readline

K, Q = map(int, input().split())
D = list(map(int, input().split()))
NXM = [list(map(int, input().split())) for _ in range(Q)]

for N, X, M in NXM:
    E = [d % M for d in D]
    cnt, tmp = 0, 0
    for e in E:
        if e > 0:
            cnt += 1
            tmp += e
    cnt *= ((N - 1) // K)
    tmp *= ((N - 1) // K)
    for i in range((N - 1) % K):
        if E[i] > 0:
            cnt += 1
            tmp += E[i]
    tmp += X % M
    print(cnt - tmp // M)
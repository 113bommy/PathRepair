TC = 1
# int(input())

for tc in range(TC):
    N, Q = map(int, input().split())
    S = input()
    P = [0 for _ in range(N + 1)]
    # P = [ord(s) - ord('a') + 1 for s in S]
    for i in range(1, N + 1):
        P[i] += P[i - 1] + ord(S[i - 1]) - ord('a') + 1

    # print(P)

    for _ in range(Q):
        l, r = map(int, input().split())
        print(P[r]-P[l-1])

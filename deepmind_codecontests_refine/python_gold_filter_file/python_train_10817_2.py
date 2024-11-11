while True:
    N = int(input())
    if N == 0:
        break
    S = []
    for i in range(N):
        S.append(int(input()))
    print((sum(S) - max(S) - min(S))//(len(S)-2))

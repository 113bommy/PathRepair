N, C, K = map(int, input().split())
T = [int(input()) for _ in range(N)]
T.sort()

a = 1; t = T[0] + K; c = 1
for i in range(1,N):
    if T[i]>t or c+1>C:
        a += 1; t = T[i] + K; c = 1
    else:
        c += 1
print(a)

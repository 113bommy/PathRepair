import heapq

N = int(input())
A = [list(map(int, input().split())) for _ in range(N)]

ans = 0
for i in range(N):
    for j in range(N):
        via_k = float('inf')
        for k in range(N):
            if A[i][j] > A[i][k] + A[k][j]:
                print(-1)
                exit()
            if k == i or k == j:
                continue
            via_k = min(via_k, A[i][k] + A[k][j])
        if i <= j:
            continue
        if A[i][j] < via_k:
            ans += A[i][j]
print(ans)

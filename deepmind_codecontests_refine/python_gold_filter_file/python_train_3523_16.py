H,W = map(int,input().split())
N = int(input())
A = list(map(int,input().split()))

ans = [[-1]*W for _ in range(H)]
now = rem = 0
for i in range(H):
    r = range(W)
    if i%2: r = reversed(r)
    for j in r:
        if rem:
            ans[i][j] = now
            rem -= 1
        else:
            now += 1
            ans[i][j] = now
            rem = A[now-1] - 1
for row in ans:
    print(*row)
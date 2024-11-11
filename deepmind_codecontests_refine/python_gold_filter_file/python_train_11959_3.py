while True:
    N = int(input())
    if N == 0:
        break
    A = [int(input()) for i in range(N)]
    ans = A [0]
    cur = 0
    for i in A:
        cur = max(cur + i,i)
        ans = max(ans,cur)
    print(ans)
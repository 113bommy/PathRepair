V, IDX = [0]*3501, [0]*3501
def solve(A, n, m, k):
    d = n-m
    B = [0]*m
    for i in range(m): B[i] = max(A[i], A[i+d])

    w = max(1, m-k)
    # print("* ", B, w)
    res = 0
    l = r = 0
    for i in range(m):
        while r > l and V[r-1] >= B[i]:
            r -= 1
        V[r], IDX[r] = B[i], i
        r += 1
        if IDX[l] == i-w: l += 1
        if i >= w-1:
            res = max(res, V[l])
            # print("+ ", i, " ", V[l], " ", res)
    return res

n = int(input())
for i in range(n):
    n, m, k, = map(int, input().split())
    A = list(map(int, input().strip().split()))
    print(solve(A, n, m, k))
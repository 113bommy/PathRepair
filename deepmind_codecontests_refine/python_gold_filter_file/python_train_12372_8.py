def main():
    N = int(input())
    A = [list(map(int, input().split())) for _ in range(N)]
    r = 0
    for i in range(N):
        for j in range(i + 1, N):
            for k in range(N):
                if k == i or k == j:
                    continue
                if A[i][k] + A[k][j] < A[i][j]:
                    return -1
                if A[i][k] + A[k][j] == A[i][j]:
                    break
            else:
                r += A[i][j]
    return r

print(main())

def main():
    N = int(input())
    A = list(map(int, input().split()))
    r = []
    ma, mi = max(A), min(A)
    if ma * mi < 0:
        if abs(mi) > abs(ma):
            ma = mi
        mi = A.index(ma)
        for i, a in enumerate(A):
            if ma * a < 0:
                r.append((mi, i))
                A[i] += ma

    if min(A) >= 0:
        for i in range(1, N):
            if A[i] < A[i - 1]:
                A[i] += A[i - 1]
                r.append((i - 1, i))
    else:
        for i in reversed(range(N - 1)):
            if A[i] > A[i + 1]:
                A[i] += A[i + 1]
                r.append((i + 1, i))

    print(len(r))
    for rx, ry in r:
        print(rx + 1, ry + 1)

main()

import sys
input = lambda: sys.stdin.readline().rstrip()

T = int(input())
for _ in range(T):
    N = int(input())
    A = [int(a) for a in input().split()]
    mi = 10**10
    ma = 0
    mama = 0
    for i in range(N-1):
        if A[i] == -1 and A[i+1] >= 0:
            mi = min(mi, A[i+1])
            ma = max(ma, A[i+1])
        elif A[i+1] == -1 and A[i] >= 0:
            mi = min(mi, A[i])
            ma = max(ma, A[i])
        elif A[i] >= 0 and A[i+1] >= 0:
            mama = max(mama, abs(A[i] - A[i+1]))
    if mi > ma:
        print(mama, 1)
    else:
        print(max((ma-mi+1) // 2, mama), (mi + ma) // 2)

import math
import sys
input = sys.stdin.readline


for _ in range(int(input())):
    n, m = map(int, input().split())
    a = []
    for i in range(n):
        p = list(map(int, input().split()))
        a.append(p)
    diag = n+m-1
    null = [0]*diag
    one = [0]*diag
    i = 0
    j = 0
    k = 0
    while j < m:
        tempi = i
        tempj = j
        while tempi < n and tempj >= 0:
            if a[tempi][tempj] == 1:
                one[k] += 1
            else:
                null[k] += 1
            tempi += 1
            tempj -= 1
        j += 1
        k += 1

    j -= 1
    i += 1

    while i < n:
        tempi = i
        tempj = j
        while tempi < n and tempj >= 0:
            if a[tempi][tempj] == 1:
                one[k] += 1
            else:
                null[k] += 1
            tempi += 1
            tempj -= 1
        i += 1
        k += 1

    ans = 0
    for t in range(diag//2):
        ones = one[t] + one[diag-1 - t]
        nulls = null[t] + null[diag - 1 - t]
        ans += min(ones, nulls)
    print(ans)
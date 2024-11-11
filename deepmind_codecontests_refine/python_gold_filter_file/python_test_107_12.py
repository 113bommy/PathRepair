import sys

T = int(sys.stdin.readline().strip())
for t in range (T):
    n, a, b = list(map(int,sys.stdin.readline().strip().split()))
    if abs(a-b) > 1 or a + b > n - 2:
        print(-1)
    else:
        ans = [-1] * n
        if a > b:
            i = 1
            c = 1
            j = 0
        elif a == b:
            i = 1
            c = -1
            j = n - 1
        else:
            a = a + 1
            i = 0
            c = -1
            j = n - 1
        while a > 0:
            ans[i] = n
            n = n - 1
            a = a - 1
            i = i + 2
        while n > 0:
            if ans[j] == -1:
                ans[j] = n
                n = n - 1
            j = j + c
        print(" ".join([str(x) for x in ans]))

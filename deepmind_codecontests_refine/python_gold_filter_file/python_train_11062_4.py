for _ in range(int(input())):
    n = int(input())
    A = [int(a) for a in input().split()]
    p = 0

    last = A[n - 1]
    break_flag = -1
    for i in range(n - 1, 0, -1):
        if A[i - 1] >= A[i]:
            continue
        else:
            break_flag = i
            break

    if break_flag != -1:
        for i in range(break_flag - 1, -1, -1):
            if A[i] >= A[i - 1]:
                continue
            else:
                p = i
                break

    print(p)
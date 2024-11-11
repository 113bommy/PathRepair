for _ in range(int(input())):
    nn = int(input())
    arr = list(map(int, input().split()))
    z = (nn-1) // 2
    p = 0
    n = 0
    for k in range(nn):
        if k % 2 != 0:
            print((-1)*(abs(arr[k])), end=" ")
        else:
            print(abs(arr[k]), end=' ')
    print()
for i in range(int(input())):
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    y = min(A)
    A.remove(y)
    x = 0
    for j in A:
        x+=(k-j)//y
    print(x)

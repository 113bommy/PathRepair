for _ in range(int(input())):
    n = int(input())
    li = list(map(int, input().split()))
    f = 0
    for i in range(n-1):
        if abs(li[i]-li[i+1]) >= 2:
            print('YES')
            print(i+1, i+2)
            f = 1
            break
    if f == 0:
        print('NO')
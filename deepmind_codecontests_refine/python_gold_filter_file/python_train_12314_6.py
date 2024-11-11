for _ in range(int(input())):
    n = input()
    a = list(map(int, input().split()))
    if len(a) == len(set(a)):
        print('NO')
    else:
        print('YES')
    
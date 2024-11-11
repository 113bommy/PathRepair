for _ in range(int(input())):
    x = int(input())
    s = list(map(int, input().split()))
    if sum(s)%2:
        print('YES')
    else:
        total = sum(1 for i in s if i%2)
        if 0 < total < x:
            print('YES')
        else: print('NO')
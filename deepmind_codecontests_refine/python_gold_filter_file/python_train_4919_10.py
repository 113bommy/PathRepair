n,s = map(int,input().split())
check = n - 1
if (s-n) <= check :
    print('NO')
else :
    arr = []
    for _ in range(n-1) :
        arr.append(2)
        s = s - 2
    arr.append(s)

    print('YES')
    print(*arr)
    print(1)
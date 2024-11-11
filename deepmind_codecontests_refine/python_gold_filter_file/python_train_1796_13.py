t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    if k > n:
        print("NO")
    elif k == n:
        print("YES")
        print('1 ' * (n - 1), end = '')
        print('1')
    elif n % 2 == 0:
        if k * 2 <= n:
            print('YES')
            print ('2 ' * (k - 1), end = '')
            print(n - ((k- 1) * 2))
        elif k % 2 == 0:
            print ('YES')
            for i in range(k - 1):
                print('1 ', end = '')
            print(n - k + 1)
        else:
            print('NO')
    else:
        if k % 2 == 1:
            print ('YES')
            for i in range(k - 1):
                print('1 ', end = '')
            print(n - k + 1)
        else:
            print("NO")
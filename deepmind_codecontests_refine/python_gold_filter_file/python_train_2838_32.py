for test_case in range(int(input())):
    x, y, z = map(int, input().split())
    arr = [x, y, z]
    arr.sort(reverse=True)
    if arr[0] == arr[1] == arr[2]:
        print('YES')
        print(x, y, z)
    elif arr[0] == arr[1]:
        print('YES')
        print(arr[0], arr[2], arr[2])
    else:
        print('NO')

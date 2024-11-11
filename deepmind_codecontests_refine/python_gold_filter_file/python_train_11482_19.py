for __ in range(int(input())):
    n = int(input())
    ar = list(map(int, input().split()))
    ans = []
    num = 0
    for i in range(1, n):
        if ar[i] != ar[0]:
            num = i
            ans.append([1, i + 1])
    if len(ans) == 0:
        print('NO')
    else:
        for i in range(1, n):
            if ar[i] == ar[0]:
                ans.append([num + 1, i + 1])
        print('YES')
        for elem in ans:
            print(*elem)
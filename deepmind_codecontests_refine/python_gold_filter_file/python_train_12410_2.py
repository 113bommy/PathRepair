for i in range(int(input())):
    input()
    f = list(map(int, input().split()))
    s = list(map(int, input().split()))
    Maxf = max(f)
    count = 0
    for j in s:
        if j > Maxf:
            count += 1
    print('NO' if count >= 1else 'YES')

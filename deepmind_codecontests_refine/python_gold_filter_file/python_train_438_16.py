for i in range(int(input())):
    n = int(input())
    s = list(map(int, input().split()))
    check = set()
    ch = 0
    for j in range(len(s)):
        now = (j + s[j]) % n
        if now in check or now > n - 1 or now < 0:
            print('NO')
            ch = 1
            break
        else:
            check.add(now)
    if ch == 0:
        print('YES')
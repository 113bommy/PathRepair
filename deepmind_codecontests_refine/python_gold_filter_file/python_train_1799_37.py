for _ in range(int(input())):
    x = int(input()) - 1
    n = 3
    ans = 1
    while x > 0:
        if n * (n + 1) // 2 <= x:
            x -= n * (n + 1) // 2
        else:
            break
        n = n * 2 + 1
        ans += 1
    print(ans)
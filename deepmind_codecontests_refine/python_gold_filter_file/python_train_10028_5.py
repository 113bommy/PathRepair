for _ in range(int(input())):
    n = int(input())
    cnt = 0
    s = 0
    i = 1
    while s < n:
        s += i
        cnt += 1
        i += 2
    print(cnt)
        
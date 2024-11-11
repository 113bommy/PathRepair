import sys

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    st = set(map(int, sys.stdin.readline().split()))
    mx = max(st)
    if mx == 1:
        print(1)
        continue
    arr = set(x % 3 for x in st)
    if mx % 3 == 0:
        print(mx // 3 + int(1 in arr or 2 in arr))
    elif mx % 3 == 1:
        cnt = mx // 3
        add = 0
        if 1 in st or mx - 1 in st:
            add += 1
        if 2 in arr:
            add += 1
        cnt += max(add, 1)
        print(cnt)
    else:
        cnt = mx // 3 + 1
        if 1 in arr:
            cnt += 1
        print(cnt)

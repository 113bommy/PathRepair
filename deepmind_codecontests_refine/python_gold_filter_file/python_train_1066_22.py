t = int(input())
for _ in range(t):
    n, x, m = [int(x) for x in input().split()]
    li = []
    l = 1010000000000
    r = 1
    flag = 0
    for i in range(m):
        a, b = [int(x) for x in input().split()]
        if flag == 0:
            if x >= a and x <= b:
                l = min(l, a)
                r = max(r, b)
                flag = 1
        else:
            if a >= l and a <= r:
                l = min(l, a)
                r = max(r, b)
            if b >= l and b <= r:
                l = min(l, a)
                r = max(r, b)
            if a >= l and b <= r:
                l = min(l, a)
                r = max(r, b)
            if a < l and b > r:
                l = min(l, a)
                r = max(r, b)
    if flag==0:
        print(1)
    else:
        print(r - l + 1)

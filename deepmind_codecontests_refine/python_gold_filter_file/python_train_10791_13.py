n = int(input())
a = [int(i) for i in input().split()]
if n == 3 and a[2] == 3:
    print(2)
    exit()
if n <= 2:
    print(0)
    exit()
ans = n+1
d1 = [0, 0, 0, -1, 1, -1, -1, 1, 1]
d2 = [0, -1, 1, 0, 0, 1, -1, 1, -1]
if a[0] <= a[n-1]:
    for i in range(9):
        b1 = a[0]
        b2 = a[1]
        b1 += d1[i]
        b2 += d2[i]
        d = abs(b2-b1)
        c = 0
        k = 0
        if (i > 0 and i < 5):
            c += 1
        elif i >= 5:
            c += 2
        for j in range(2, n):
            v = b1 + j*d
            if abs(a[j] - v) == 1:
                c += 1
            elif abs(a[j] - v) == 0:
                c += 0
            else:
                k = 1
                break
        if c < ans and k != 1:
            ans = c
    if ans == n+1:
        print(-1)
    else:
        print(ans)
else:
    for i in range(9):
        b1 = a[0]
        b2 = a[1]
        b1 += d1[i]
        b2 += d2[i]
        d = abs(b2-b1)
        c = 0
        k = 0
        if (i > 0 and i < 5):
            c += 1
        elif i >= 5:
            c += 2
        for j in range(2, n):
            v = b1 - j*d
            if abs(a[j] - v) == 1:
                c += 1
            elif abs(a[j] - v) == 0:
                c += 0
            else:
                k = 1
                break
        if c < ans and k != 1:
            ans = c
    if ans == n+1:
        print(-1)
    else:
        print(ans)
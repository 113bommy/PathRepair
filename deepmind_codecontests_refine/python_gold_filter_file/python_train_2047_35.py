n, m, k = map(int, input().split())
if k < n:
    print(k+1, 1)
elif k <= m + n - 2:
    print(n, k-n+2)
else:
    if (n == 1 and m == 2 and k == 3):
        print(1, 2)
    elif (n == 1 and m == 2 and k == 2):
        print(2, 2)
    else:
        k = k - (n + m - 1)
        row, col = divmod(k, m-1)
        if row % 2 == 0:
            print(n-1-row, m - col)
        else:
            print(n-1-row, 2+col)

n = list(map(int, input().split()))
if n[0] == 1 and n[1] == 10:
    print(-1)
else:
    if n[1] == 10:
        x = str(1) * (n[0] - 1) + '0'
        print(x)
    else:
        y = str(n[1]) * n[0]
        print(y)
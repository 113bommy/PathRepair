def lottery():
    n = int(input())
    x = 0
    if n >= 100:
        a = n - n % 100
        x += a/100
        a = 0
        n = n % 100
    if n >= 20:
        a = n - n % 20
        x += a/20
        a = 0
        n = n % 20
    if n >= 10:
        a = n - n % 10
        x += a/10
        a = 0
        n = n % 10
    if n >= 5:
        a = n - n % 5
        x += a/5
        a = 0
        n = n % 5
    if n >= 1:
        a = n - n % 1
        x += a/1
        a = 0
        n = n % 1
    print(int(x))
    
lottery()
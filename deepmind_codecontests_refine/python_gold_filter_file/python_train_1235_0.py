while True:
    n = int(input())
    if n == 0:
        break
    f = 1
    for i in range(n):
        f *= i + 1
    i = 0
    f_str = str(f)
    while True:
        if f_str[-1] == "0":
            i += 1
            f_str = f_str[:-1]
        else:
            break
    print(i)


for i in range(int(input())):
    s = input()
    t = input()
    if set(s) & set(t) != set():
        print('YES')
    else:
        print('NO')
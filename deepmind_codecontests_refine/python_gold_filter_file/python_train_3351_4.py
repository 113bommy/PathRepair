for i in range(int(input())):
    s, t = input(), input()
    f = 1
    for j in set(s):
        if j in set(t):
            f = 0
            break
    print(['YES', 'NO'][f])

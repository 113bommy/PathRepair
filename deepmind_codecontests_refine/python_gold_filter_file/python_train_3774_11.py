def calc(s):
    alpha = 'abcdefghijklmnopqrstuvwxyz'
    r = set()
    s = list(s)

    for i in range(len(s)):
        c = s[i]
        for j in alpha:
            s[i] = j
            r.add(''.join(s))
        s[i] = c
    return r


t = int(input())
for T in range(t):
    n, m = [int(x) for x in input().split()]
    a = set()

    for i in range(n):
        if i == 0:
            a = calc(input())
##            print(len(a), a)
        else:
            a = a & calc(input())

    if len(a) == 0:
        print(-1)
    else:
        print(list(a)[0])

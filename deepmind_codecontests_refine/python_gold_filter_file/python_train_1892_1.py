import sys
#sys.stdin = open('inE', 'r')
t = int(input())
for ti in range(t):
    n,m = map(int, input().split())
    a = []
    for i in range(n):
        a.append(input())
    top = {}
    bot = {}
    l = {}
    r = {}
    res = True
    for y in range(n):
        for x in range(m):
            c = a[y][x]
            if c != '.':
                if c not in top:
                    top[c] = y
                    bot[c] = y
                    l[c] = x
                    r[c] = x
                else:
                    if top[c] == y:
                        r[c] = x
                        xi = x - 1
                        while xi >= 0 and a[y][xi] != c:
                            if a[y][xi] == '.' or a[y][xi] < c:
                                res = False
                            xi -= 1
                    elif l[c] == x and r[c] == x:
                        bot[c] = y
                        yi = y - 1
                        while yi >= 0 and a[yi][x] != c:
                            if a[yi][x] == '.' or a[yi][x] < c:
                                res = False
                            yi -= 1
                    else:
                        res = False
    if len(top) == 0:
        sys.stdout.write('YES\n')
        sys.stdout.write('0\n')
    elif res:
        mxc = max(top)
        cnt = ord(mxc) & 31
        sys.stdout.write('YES\n')
        sys.stdout.write(str(cnt)+'\n')
        for i in range(cnt):
            ci = chr(ord('a') + i)
            if ci not in top:
                ci = mxc
            sys.stdout.write(f'{top[ci]+1} {l[ci]+1} {bot[ci]+1} {r[ci]+1}\n')
    else:
        sys.stdout.write('NO\n')

USE_STDIO = False

if not USE_STDIO:
    try: import mypc
    except: pass

def main():
    n, m, k = map(int, input().split(' '))
    if 2 * m * n % k:
        print('NO')
        return
    print('YES')
    t = 2 * m * n // k
    if k == 2:
        x1, y1 = 0, 0
        x2, y2 = 0, m
        x3, y3 = n, 0
    elif t <= m:
        x1, y1 = 0, 0
        x2, y2 = 1, 0
        x3, y3 = 0, t
    else:
        q = t // m
        p = m * (q + 1) - t
        x1, y1 = 0, 0
        x2, y2 = 1, m
        x3, y3 = q + 1, p
    print(x1, y1)
    print(x2, y2)
    print(x3, y3)


if __name__ == '__main__':
    main()




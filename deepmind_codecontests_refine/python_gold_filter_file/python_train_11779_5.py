import sys

input = sys.stdin.readline

x, y, z = map(int, input().split())
a, b, c = map(int, input().split())

if x > a:
    print('NO')
    sys.exit(0)
else:
    if y > (a-x) + b:
        print('NO')
        sys.exit(0)
    else:
        if (a-x) + b - y + c >= z:
            print('YES')
        else:
            print('NO')
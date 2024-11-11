a, b, c = map(int, input().split())

if c == 0:
    if a == b:
        print("YES")
    else:
        print("NO")
    exit(0)

k = (b - a) / c

if k == int(k) and k >= 0:
    print("YES")
else:
    print("NO")

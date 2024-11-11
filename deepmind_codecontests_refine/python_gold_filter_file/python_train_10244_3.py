def main():
    a, b = map(int, input().split())
    s, t = input(), -100
    x = sum({"L": -1, "R": 1}.get(c, 0) for c in s)
    y = sum({"D": -1, "U": 1}.get(c, 0) for c in s)
    if x and y:
        t += min(a // x, b // y)
    elif x:
        t += a // x
    elif y:
        t += b // y
    if t > 0:
        a -= t * x
        b -= t * y
    for c in s * 101:
        if a == 0 == b:
            print("Yes")
            return
        a -= {"L": -1, "R": 1}.get(c, 0)
        b -= {"D": -1, "U": 1}.get(c, 0)
    print("No")


if __name__ == '__main__':
    main()

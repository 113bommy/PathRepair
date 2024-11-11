def main():
    a, b, c = (int(i) for i in input().split())
    ans = min(a//3, b//2, c//2)
    a -= ans*3
    b -= ans*2
    c -= ans*2
    ans *= 7
    # print(a, b, c, ans)
    if c == 0:
        if b == 0:
            if a == 0:
                pass
            else:
                ans += 2
        elif b == 1:
            if a == 0:
                ans += 1
            elif a == 1:
                ans += 2
            else:
                ans += 3
        else:
            if a == 0:
                ans += 1
            elif a == 1:
                ans += 2
            else:
                ans += 4
    elif c == 1:
        if b == 0:
            if a == 0:
                ans += 1
            else:
                ans += 2
        elif b == 1:
            if a == 0:
                ans += 2
            elif a == 1:
                ans += 3
            elif a == 2:
                ans += 4
            else:
                ans += 5
        else:
            if a == 0:
                ans += 2
            elif a == 1:
                ans += 3
            elif a == 2:
                ans += 5
            else:
                ans += 6
    else:
        if b == 0:
            if a == 0:
                ans += 1
            else:
                ans += 3
        elif b == 1:
            if a == 0:
                ans += 2
            elif a == 1:
                ans += 4
            elif a == 2:
                ans += 5
            else:
                ans += 6
        else:
            if a == 0:
                ans += 2
            elif a == 1:
                ans += 5
            elif a == 2:
                ans += 6
            else:
                ans += 7
    print(ans)


if __name__ == '__main__':
    main()

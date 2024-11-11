def main():
    p = int(input())
    if p < 5:
        print(1 )
        return
    res, r = 0, range(p - 2)
    for x in range(2, p):
        xx = x
        for _ in r:
            xx %= p
            if xx == 1:
                break
            xx *= x
        else:
            if xx % p == 1:
                res += 1
    print(res)


if __name__ == '__main__':
    main()

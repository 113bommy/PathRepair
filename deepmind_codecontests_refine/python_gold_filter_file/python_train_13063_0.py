def main():
    m, tt = int(input()), [0] * 4
    for i in 0, 2:
        h, a = map(int, input().split())
        x, y = map(int, input().split())
        ha = (h, a)
        for t in range(1, m * 2):
            h = (h * x + y) % m
            if h in ha:
                if h == ha[0]:
                    if tt[i]:
                        tt[i] = t - tt[i]
                        break
                    else:
                        tt[i] = t
                else:
                    if tt[i + 1]:
                        tt[i] = t - tt[i + 1]
                        break
                    else:
                        tt[i + 1] = t
    step1, shift1, step2, shift2 = tt if tt[0] > tt[2] else tt[2:] + tt[:2]
    if shift1 == shift2 != 0:
        print(shift1)
        return
    if step1 and not step2 and shift1 and shift1 <= shift2 and not (shift2 - shift1) % step1:
        print(shift2)
        return
    if all(tt):
        if step2 == 1:
            print(shift1 if shift1 >= shift2 else shift2 + (shift2 - shift1) % step1)
            return
        for t in range(shift1 - shift2, shift1 - shift2 + step1 * step2, step1):
            if not t % step2:
                print(t + shift2)
                return
    print(-1)


if __name__ == '__main__':
    main()

def main():
    input()
    aa = [0] * 200002
    for i, x in enumerate(map(int, input().split()), 1):
        x *= 2
        j, step = aa[x], aa[x + 1]
        if j:
            if step:
                if j + step != i:
                    aa[x + 1] = -1
            else:
                aa[x + 1] = i - j
        aa[x] = i
    res = []
    for x in range(2, len(aa), 2):
        j, step = aa[x], aa[x + 1]
        if j and step != -1:
            res.append(' '.join((str(x // 2), str(step))))
    print(len(res))
    print('\n'.join(res))


if __name__ == '__main__':
    main()
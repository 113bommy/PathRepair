def printres(res):
    print("YES")
    print(' '.join(map(str, res)))

def main():
    cc = [int(a) for a in input().split()]
    nz = []
    for i,c in enumerate(cc):
        if c > 0:
            nz.append(i)
    if len(nz) == 1:
        if cc[nz[0]] == 1:
            printres([nz[0]])
        else:
            print("NO")
        return
    elif len(nz) == 2:
        if nz[1] != nz[0] + 1:
            print("NO")
            return
        df = cc[nz[1]] - cc[nz[0]]
        if abs(df) > 1:
            print("NO")
            return
        if df == 1:
            printres([nz[1]] + [nz[0], nz[1]] * cc[nz[0]])
        elif df == 0:
            printres([nz[0], nz[1]] * cc[nz[0]])
        else:
            printres([nz[0], nz[1]] * cc[nz[1]] + [nz[0]])
        return
    elif len(nz) == 3:
        if nz[2] != nz[1] +1 or nz[1] != nz[0] + 1:
            print("NO")
            return
        df = cc[nz[0]] + cc[nz[2]] - cc[nz[1]]
        if abs(df) > 1:
            print("NO")
            return
        if df == 1:
            printres([nz[0], nz[1]] * cc[nz[0]] + [nz[2], nz[1]] * (cc[nz[2]] -1) + [nz[2]])
        elif df == 0:
            printres([nz[0], nz[1]] * cc[nz[0]] + [nz[2], nz[1]] * cc[nz[2]])
        else:
            printres([nz[1]] + [nz[0], nz[1]] * cc[nz[0]] + [nz[2], nz[1]] * cc[nz[2]])
        return
    else:
        df = cc[0] - cc[1] + cc[2] - cc[3]
        if abs(df) > 1:
            print("NO")
            return
        y = min(cc[1] - cc[0], cc[2] - cc[3])
        if y < 0:
            print("NO")
            return
        base = [0,1] * cc[0] + [2, 1] * y + [2, 3] * cc[3]
        if df == 1:
            printres(base + [2])
        elif df == 0:
            printres(base)
        else:
            printres([1] + base)
        return


if __name__ == "__main__":
    main()
from sys import stdin, stdout


def getmaxdonimo(n, aa):

    bcnt = 0
    wcnt = 0
    isblack = True

    for a in aa:

        bcnt += a // 2
        wcnt += a // 2

        if isblack:
            bcnt += a % 2
        else:
            wcnt += a % 2

        isblack = not isblack

    #print(bcnt)
    #print(wcnt)

    return min(bcnt, wcnt)


if __name__ == '__main__':
    n = int(stdin.readline())
    aa = list(map(int, stdin.readline().split()))

    res = getmaxdonimo(n, aa)

    stdout.write(str(res))
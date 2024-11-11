def ispossible(charge, playcost, lowplaycost, playcnt, allcnt):
    return charge > playcost*playcnt + lowplaycost*(allcnt - playcnt)


def solution():
    k, n, a, b = map(int, input().split())
    if k <= b*n:
        return -1

    l = 0
    r = n + 1
    while r - l > 1:
        m = (r+l)//2
        if ispossible(k, a, b, m, n) == True:
            l = m
        else:
            r = m
    return l



def main():
    test = int(input())
    for i in range(test):
        print(solution())
    return


if __name__ == "__main__":
    main()

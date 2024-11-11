def read_ints():
    return [int(x) for x in input().rstrip().rsplit()]


if __name__ == '__main__':
    nn = int(input())

    while nn > 0:
        n, m, rb, cb, rd, cd = read_ints()

        dr = 1
        dc = 1

        counter = 0
        while True:
            if rb == rd or cb == cd:
                break
            counter += 1
            if rb + dr > n or rb + dr < 1:
                dr *= -1
            if cb + dc > m or cb + dc < 1:
                dc *= -1
            rb += dr
            cb += dc

        print(counter)

        nn -= 1

def read():
    return input().strip()


def main():
    n = int(read())
    a, b = read(), read()
    solution = []
    steps = 0

    if sorted(a) != sorted(b):
        print('-1')
        return

    for i in range(n):
        first_occur = a.index(b[i])
        steps += first_occur
        solution.append((i + first_occur, first_occur))
        a = a[:first_occur] + a[first_occur+1:]

    print(steps)
    for start, iterations in solution:
        for j in range(iterations):
            print(start - j, end=' ')


if __name__ == '__main__':
    main()
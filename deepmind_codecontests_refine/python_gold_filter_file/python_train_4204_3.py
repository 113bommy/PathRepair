def main():
    input()
    x, l = 0, [0]
    for a in map(int, input().split()):
        x ^= a
        l.append(x)
    x = 0
    for i, a in enumerate(l):
        for j in range(i):
            y = a ^ l[j]
            if x < y:
                x = y
    print(x)


if __name__ == '__main__':
    main()

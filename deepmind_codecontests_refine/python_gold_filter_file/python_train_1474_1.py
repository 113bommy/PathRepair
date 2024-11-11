def main():
    n = int(input())
    a = sorted([int(x) for x in input().split()])

    up, down = set(), set()

    for x in a:
        if x in up and x in down:
            print("NO")
            return
        elif x in down:
            up.add(x)
        else:
            down.add(x)

    print("YES")
    print(len(up))
    print(' '.join([str(x) for x in sorted(up)]))
    print(len(down))
    print(' '.join([str(x) for x in sorted(down, reverse=True)]))

if __name__ == '__main__':
    main()
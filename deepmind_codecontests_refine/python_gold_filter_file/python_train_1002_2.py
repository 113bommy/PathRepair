def main():
    n, m = map(int, input().split())
    aa, bb = [{i for i, c in enumerate(input()) if c == '#'} for _ in range(n)], []
    for a in aa:
        if a:
            for b in bb:
                c = a & b
                if c and a != b:
                    print('No')
                    return
            bb.append(a)
    print('Yes')


if __name__ == '__main__':
    main()

def main():
    from itertools import combinations
    s, res = input(), ()
    for le in range(len(s)):
        for p in combinations(s, le + 1):
            if res < p and p == p[::-1]:
                res = p
    print(''.join(res))


if __name__ == '__main__':
    main()

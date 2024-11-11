def main():
    n, m = map(int, input().split())
    aa, bb = [m] * 200001, [0] * 200001
    for i in sorted(map(int, input().split())):
        aa[i] -= 1
        t = 0
        while i:
            t += 1
            i //= 2
            if aa[i] <= 0:
                continue
            aa[i] -= 1
            bb[i] += t
    print(min(b for a, b in zip(aa, bb) if a <= 0))


if __name__ == '__main__':
    main()

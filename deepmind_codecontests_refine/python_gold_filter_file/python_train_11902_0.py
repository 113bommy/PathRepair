def solve(n, x, t):
    d = min(t // x, n)
    print(d * (n - d) + d * (d - 1) // 2)


def main():
    for _ in range(int(input())):
        solve(*map(int, input().split()))


if __name__ == '__main__':
    main()

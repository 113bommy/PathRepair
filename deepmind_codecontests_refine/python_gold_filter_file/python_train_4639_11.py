
def get_ints():
    return tuple(map(int, input().split()))


def main():
    x, y = get_ints()
    n = int(input())
    r = None
    for _ in range(n):
        a, b, v = get_ints()
        t = ((x-a) ** 2 + (y-b) ** 2) ** 0.5 / v
        if r is None or r > t:
            r = t
    print(r)

if __name__ == '__main__':
    main()

# http://codeforces.com/problemset/problem/161/A
# A. Dress'em in Vests!


def read_input():
    n, m, x, y = [int(i) for i in input().split(" ")]
    a = [int(i) for i in input().split(" ")]
    b = [int(i) for i in input().split(" ")]
    return (n, m, x, y, a, b)


def dress_them(n, m, x, y, a, b):
    i = 0
    j = 0
    dress_count = 0
    dress_pairs = []
    while j < len(b) and i < len(a):
        if a[i] - x <= b[j] and a[i] + y >= b[j]:
            dress_count += 1
            dress_pairs.append((i + 1, j + 1))
            j += 1
            i += 1
        elif a[i] - x < b[j]:
            i += 1
        else:
            j += 1
    return (dress_count, dress_pairs)


def main():
    n, m, x, y, a, b = read_input()
    count, pairs = dress_them(n, m, x, y, a, b)
    print(count)
    for pair in pairs:
        print("{} {}".format(pair[0], pair[1]))


if __name__ == '__main__':
    main()

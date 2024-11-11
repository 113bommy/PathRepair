import itertools


def main():
    n, m = map(int, input().split())
    counter = n - 1
    print(100019, 100019)
    for i in range(1, n - 1):
        print(i, i + 1, 1)
    print(n -1, n, 100019 - (n - 2))

    for u, v in itertools.combinations(range(n), r=2):
        if counter == m:
            break
        u += 1
        v += 1
        if v - u == 1:
            continue
        print(u, v, 10**9)
        counter += 1

main()
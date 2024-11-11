def solve(n):
    assert n % 2 == 0

    if n % 4 != 0:
        return "NO"

    assert n >= 4

    even_a = list(range(2, n + 2, 2))
    even_a[-1] += 100000
    assert len(even_a) == n // 2

    odd_a = list(range(1, n - 1, 2))
    assert len(odd_a) == n // 2 - 1

    pair_sum = sum(even_a)
    odd_sum = sum(odd_a)

    a = [*even_a, *odd_a, pair_sum - odd_sum]
    assert len(set(a)) == len(a)

    return "YES\n" + " ".join(map(str, a))


def main():
    T = int(input())
    for _ in range(T):
        n = int(input())
        print(solve(n))


if __name__ == "__main__":
    main()

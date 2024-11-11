from collections import Counter


def main():
    n = int(input())
    s1, s2 = input().strip(), input().strip()

    ans = 0
    for i in range(n // 2):
        c = Counter()
        c[s1[i]] += 1
        c[s2[i]] += 1
        c[s1[n - i - 1]] += 1
        c[s2[n - i - 1]] += 1
        values = sorted(c.values(), reverse=True)

        if values == [3, 1]:
            ans += 1
        elif values == [2, 1, 1]:
            ans += 1 + (s1[i] == s1[n - i - 1])
        elif values == [1, 1, 1, 1]:
            ans += 2

    if n % 2 == 1 and s1[n // 2] != s2[n // 2]:
        ans += 1

    print(ans)


if __name__ == '__main__':
    main()
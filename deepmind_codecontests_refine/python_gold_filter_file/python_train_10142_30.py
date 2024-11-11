def main():
    [a, b] = [int(_) for _ in input().split()]
    wins = [''] * 7

    for i in range(1, 7):
        points_a = abs(a - i)
        points_b = abs(b - i)
        wins[i] = 'a' if points_a < points_b \
            else 'b' if points_b < points_a \
            else '-'

    print(wins.count('a'), wins.count('-'), wins.count('b'))


if __name__ == '__main__':
    main()

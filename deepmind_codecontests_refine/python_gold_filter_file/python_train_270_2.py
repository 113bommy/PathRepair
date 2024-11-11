def read():
    return [int(v) for v in input().split()]


def main():
    n = read()[0]
    a = []
    for _ in range(n):
        a.append(read()[0])

    player1, player2, specator = 1, 2, 3
    for winner in a:
        if winner == player1:
            player2, specator = specator, player2
        elif winner == player2:
            player1, specator = specator, player1
        else:
            print('NO')
            break
    else:
        print('YES')


if __name__ == '__main__':
    main()

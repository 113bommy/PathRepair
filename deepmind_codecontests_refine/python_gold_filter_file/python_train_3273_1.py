def main():
    n = int(input())
    teams = [list(map(int, input().split())) for _ in range(n)]
    ans = [[n - 1, 0] for _ in range(n)]
    home = [0] * ((10 ** 5) + 1)

    for i in range(n):
        home[teams[i][0]] += 1

    for i in range(n):
        ans[i][0] += home[teams[i][1]]
        ans[i][1] = n - 1 - home[teams[i][1]]

    for i in range(n):
        ans[i] = '{} {}'.format(ans[i][0], ans[i][1])

    print('\n'.join(ans))

if __name__ == '__main__':
    main()
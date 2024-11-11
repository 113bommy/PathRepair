from sys import stdin


def main():
    n = (int(stdin.readline().strip()) + 1) // 2
    for i in range(1, n + 1):
        l = ['*'] * (n - i)
        for j in range(i):
            l.append('D')
        print(''.join(l + l[n - 2::-1]))
    for i in range(n - 1, 0, -1):
        l = ['*'] * (n - i)
        for j in range(i):
            l.append('D')
        print(''.join(l + l[n - 2::-1]))

main()

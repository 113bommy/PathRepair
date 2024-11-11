from sys import stdin


def main():
    n, v = map(int, stdin.readline().strip().split())
    res = []
    for i in range(n):
        l = list(map(int, stdin.readline().strip().split()))
        nn = l.pop(0)
        if any(e < v for e in l):
            res.append(i + 1)
    res.sort()
    print(len(res))
    print(*res)


main()

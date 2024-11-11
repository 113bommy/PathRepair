from sys import stdin


def main():
    input = lambda: stdin.readline()[:-1]
    T = int(input())
    for _ in [0] * T:
        N = int(input())
        ans = [1] * N
        print(*ans)


main()

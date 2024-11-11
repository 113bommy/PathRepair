from sys import stdin


def main():
    input = lambda: stdin.readline()[:-1]
    T = int(input())
    for _ in [0] * T:
        N, K = map(int, input().split())
        d, m = divmod(K, (N - 1))
        ans = d * N
        if m:
            ans += m
        else:
            ans -= 1
        print(ans)


main()

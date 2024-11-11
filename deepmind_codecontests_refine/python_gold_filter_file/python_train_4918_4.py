import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, a, b = list(map(int, input().split()))
    alpha = "abcdefghijklmnopqrstuvwxyz"
    times, rem = divmod(n, b)
    res = alpha[:b] * times
    res += alpha[:rem]
    print(res)

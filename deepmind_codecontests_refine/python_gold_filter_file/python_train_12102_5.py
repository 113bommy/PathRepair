# from sys import stdin
# input = stdin.buffer.readline
for _ in range(int(input())):
    n, k = map(int, input().split())
    *a, = map(int, input().split())
    s = list(set(a))
    if len(s) > k:
        print(-1)
    else:
        s = s + [1] * (k - len(s))
        print(k * 100)
        print(*s * 100)

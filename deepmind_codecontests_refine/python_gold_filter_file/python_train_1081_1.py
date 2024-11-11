read = lambda: map(int, input().split())
n = int(input())
a = list(read())
b = list(read())
dp = [0] * n
ch = [0]


def get(i, x):
    return b[i] * x + dp[i]


def f1():
    if len(ch) < 2:
        return 0
    return get(ch[0], a[i]) >= get(ch[1], a[i])


def f2():
    if len(ch) < 2:
        return 0
    i1 = ch[-1]
    x = (dp[i1] - dp[i]) / (b[i] - b[i1])
    return get(ch[-2], x) <= get(i, x)


for i in range(1, n):
    while f1():
        ch.pop(0)
    dp[i] = get(ch[0], a[i])
    while f2():
        ch.pop()
    ch.append(i)
print(dp[n - 1])

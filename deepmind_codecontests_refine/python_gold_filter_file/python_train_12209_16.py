
import math
from sys import stdin, stdout

ip = lambda: int(stdin.readline())
inp = lambda: map(int, stdin.readline().split())
ips = lambda: stdin.readline().rstrip()
out = lambda x: stdout.write(str(x) + "\n")


def qpow(a, b, m):
    ans = 1
    while b:
        if b & 1:
            ans *= a
            ans %= m
        a *= a
        a %= m
        b >>= 1
    return ans


if __name__ == '__main__':
    t = ip()
    for _ in range(t):
        n, T = inp()
        a = list(inp())
        ans = []
        if T&1:
            for i in range(n):
                if a[i] <= T // 2:
                    ans.append(0)
                else:
                    ans.append(1)
        else:
            flag = 0
            for i in range(n):
                if a[i] < T // 2:
                    ans.append(0)
                elif a[i] == T // 2:
                    ans.append(flag)
                    flag = 1 - flag
                else:
                    ans.append(1)
        print(*ans)
from sys import stdin, stdout
import sys

# 2 2
#  3  11
# 12   8
def multiples_and_power_differences(n, m, b_a):
    # r = 1
    # for i in range(2, 17):
    #    r = lcm(r, i)
    r = 720720

    for i in range(n):
        for j in range(m):
            if (i+j)%2 == 0:
                b_a[i][j] = r
            else:
                b_a[i][j] = r - (b_a[i][j]**4)


def lcm(a, b):
    g = gcd(a, b)
    return a*b//g


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)


try:
    n, m = map(int, stdin.readline().split())
    b_a = []
    for _ in range(n):
        b_a.append(list(map(int, stdin.readline().split())))
    multiples_and_power_differences(n, m, b_a)
    for b in b_a:
        stdout.write(' '.join(map(str, b)) + '\n')
except:
    print(sys.exc_info())

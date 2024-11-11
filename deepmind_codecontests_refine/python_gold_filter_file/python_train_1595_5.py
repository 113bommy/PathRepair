from sys import stdin, stdout
import math


def education(n, c, a_a, b_a):

    r = 2**63-1
    m = 0
    d = 0
    for i in range(n):
        if m > c:
            r = min(r, d)
        else:
            r = min(r, d + math.ceil((c - m) / a_a[i]))

        if i < n-1:
            if b_a[i] > m:
                ld = math.ceil((b_a[i] - m) / a_a[i])
                d += ld + 1
                m += ld*a_a[i] - b_a[i]
            else:
                m -= b_a[i]
                d += 1

    return r


t = int(stdin.readline())
for _ in range(t):
    n, c = map(int, stdin.readline().split())
    a_a = list(map(int, stdin.readline().split()))
    b_a = list(map(int, stdin.readline().split()))
    r = education(n, c, a_a, b_a)
    stdout.write(str(r) + '\n')

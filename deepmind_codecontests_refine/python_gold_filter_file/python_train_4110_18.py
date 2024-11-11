"""
http://codeforces.com/problemset/problem/501/A
"""


def points(p, t):
    return max((3 * p) // 10, p - (p * t) // 250)


strings = ["Misha", "Vasya", "Tie"]
[a, b, c, d] = [int(item) for item in input().split(' ')]

pm = points(a, c)
pv = points(b, d)

if pm > pv:
    print(strings[0])
elif pm < pv:
    print(strings[1])
else:
    print(strings[2])

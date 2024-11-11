# https://codeforces.com/problemset/problem/20/B


def find_roots(a, b, c):
    if (a, b, c) == (0, 0, 0):
        return None
    if (a, b) == (0, 0):
        return []
    if a == 0:
        return [-c / b]
    d = b**2 / (4 * a**2) - c / a
    if d < 0:
        return []
    m = -b / (2 * a)
    if d == 0:
        return [m]
    return [m - d**0.5, m + d**0.5]


if __name__ == '__main__':
    a, b, c = map(float, input().split())
    roots = find_roots(a, b, c)
    if roots is None:
        print(-1)
    else:
        print(len(roots))
        for r in roots:
            print('{:.10f}'.format(r))
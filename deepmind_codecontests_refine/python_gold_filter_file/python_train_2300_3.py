from itertools import repeat
from math import gcd


def p(n, m):
    if m < n - 1:
        return 'Impossible'
    ans = list(zip(repeat(1), range(2, n + 1)))
    for i in range(2, n + 1):
        for j in range(i + 1, n + 1):
            if gcd(i, j) == 1:
                ans.append([i, j])
            if len(ans) >= m:
                break
        if len(ans) >= m:
            break

    if len(ans) < m:
        return 'Impossible'
    return '\n'.join([
        'Possible',
        *(' '.join(str(x) for x in pair) for pair in ans[:m]),
    ])


print(p(*map(int, input().split())))

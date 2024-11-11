"""
Codeforces Educational Round 2

Problem 600 A. Extract Numbers

@author yamaton
@date 2015-11-30
"""

import re

def solve(s):
    def is_int(w):
        return w and all(c.isdigit() for c in w) and str(int(w)) == w

    words = re.split("[,;]", s)
    ints = [w for w in words if is_int(w)]
    rest = [w for w in words if not is_int(w)]
    if not ints:
        ints = None
    if not rest:
        rest = None
    return ints, rest


def main():
    s = input().strip()
    results = solve(s)
    for res in results:
        if res is None:
            print('-')
        else:
            print('"%s"' % ','.join(res))


if __name__ == '__main__':
    main()

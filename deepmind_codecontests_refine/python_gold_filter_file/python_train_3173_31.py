# 509B
# θ(Σ(ai)) time
# θ(n) space

__author__ = 'artyom'


# SOLUTION

def main():
    n, k = read(3)
    mn = 101
    mx = 0
    a = read(3)
    for v in a:
        if v < mn:
            mn = v
        if v > mx:
            mx = v
    if mx - mn > k:
        write('NO')
        return
    write('YES')
    for v in a:
        write([1] * mn + list(range(1, v - mn + 1)))


# HELPERS

def read(mode=1, size=None):
    # 0: String
    # 1: Integer
    # 2: List of strings
    # 3: List of integers
    # 4: Matrix of integers
    if mode == 0: return input().strip()
    if mode == 1: return int(input().strip())
    if mode == 2: return input().strip().split()
    if mode == 3: return list(map(int, input().strip().split()))
    a = []
    for _ in range(size):
        a.append(read(3))
    return a


def write(s="\n"):
    if s is None: s = ''
    if isinstance(s, tuple) or isinstance(s, list): s = ' '.join(map(str, s))
    s = str(s)
    print(s, end="\n")


main()
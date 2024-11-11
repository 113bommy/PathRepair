# 78B
# θ(n) time
# θ(n) space

__author__ = 'artyom'


# SOLUTION

def main():
    n = read()
    s = 'ROYGBIV'
    return s * (n // 7) + 'GBIVGB'[:n % 7]


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


def write(s='\n'):
    if s is None: s = ''
    if isinstance(s, tuple) or isinstance(s, list): s = ' '.join(map(str, s))
    s = str(s)
    print(s)


write(main())
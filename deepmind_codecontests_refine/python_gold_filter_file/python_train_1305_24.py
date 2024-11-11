a, b, c = map(int, input().split())
def solve(a, b, c):
    if c == 0:
        return a == b
    elif c < 0:
        a, b, c = -a, -b, -c
    return b >= a and b%c == a%c

print('YES' if solve(a, b, c) else 'NO')

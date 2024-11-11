def min(a, b):
    if a < b:
        return a
    else:
        return b
def abs(a, b):
    if a - b < 0:
        return -1 * (a - b)
    else:
        return a - b
a, b, c = map(int , input().split())
if abs(a, b) <= 1:
    print(b + a + 2 * c)
else:
    print(int(min(2 * a + 1, 2 * b + 1) + 2 * c))
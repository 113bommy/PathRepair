n = int(input())
aa = list(map(lambda x: int(x)-1, list(input())))

def parity(n, r):
    # parity of n choose r
    # via https://math.stackexchange.com/questions/233269/odd-and-even-numbers-in-pascals-triangle-sierpinskis-triangle
    if n <= 1:
        return 1
    if r == 1:
        return n % 2
    if r == 0:
        return 1
    if n % 2 == 0 and r % 2 != 0:
        return 0
    return parity(n//2, r//2)

def ab(x):
    if x < 0:
        return -x
    return x

ans = 0
for i, a in enumerate([a % 2 for a in aa]):
    p = parity(n-1, i)
    if p == 1:
        ans = ab(ans - a)

if ans == 1:
    print(1)
    exit(0)

if 1 in aa:
    print(0)
    exit(0)

ans = 0
for i, a in enumerate([a // 2 for a in aa]):
    p = parity(n-1, i)
    if p == 1:
        ans = ab(ans - a)
print(ans * 2)


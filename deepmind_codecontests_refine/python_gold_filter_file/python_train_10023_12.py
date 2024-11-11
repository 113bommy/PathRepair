
def can_construct():

    if m % 2 == 1:
        for _ in range(n):
            _, _ = map(int, input().split())
            _, _ = map(int, input().split())
        print('NO')
        return

    tiles = set()
    for i in range(n):
        tl, tr = map(int, input().split())
        bl, br = map(int, input().split())
        if tr == bl:
            for _ in range(i+1, n):
                _, _ = map(int, input().split())
                _, _ = map(int, input().split())

            print('YES')
            return

        tiles.add((tl, tr, bl, br))

    print('NO')
    return


t = int(input())

for _ in range(t):
    n, m = map(int, input().split())

    can_construct()

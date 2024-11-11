T = int(input())
for _ in range(T):
    n, m, x, y = map(int, input().split())
    road = []
    price = 0
    for _ in range(n):
        tmp = input()
        road.append(tmp)

    for row in road:
        parts = row.split('*')
        for segment in parts:

            tmp1 = segment.count('.') * x
            tmp2 = ((len(segment) // 2) * y) + ((len(segment) - ((len(segment) // 2) * 2)) * x)
            price += min(tmp1, tmp2)

    print(price)

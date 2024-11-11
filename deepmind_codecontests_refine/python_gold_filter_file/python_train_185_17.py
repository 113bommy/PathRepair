n, p = map(int, input().split())

p2 = round(p ** (1 / n))

for i in range(p2, 0, -1):
    if p % (i ** n) == 0:
        print(i)
        break
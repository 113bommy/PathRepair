n, a, b, c = map(int, input().split())
res = None
for i in range(4001):
    if i * a > n:
        break
    for j in range(4001):
        if i * a + j * b > n:
            break
        thing = n - i * a - j * b
        if thing >= 0 and thing % c == 0:
            stuff = i + j + thing // c
            if res is None or stuff > res:
                res = stuff
print(res)

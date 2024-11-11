n, m = map(int, input().split())
z = '#'
v = '.'
count = 0
for i in list(range(n)):
    if i % 2 == 0:
        print(z * m)
    else:
        if count % 2 != 0:
            print(z + v * (m - 1))
        else:
            print(v * (m - 1) + z)
        count += 1

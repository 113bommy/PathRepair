n = int(input())

z = [int(x) for x in input().split()]

a = n - z[0]

for i in range(1, n):
    b = z[i]
    v = i

    if b <= v:
        w = v - b
    else:
        w = n - b + v

    if w != n - a:
        print('No')
        exit(0)

    if w != 0:
        a = n - a

print('Yes')
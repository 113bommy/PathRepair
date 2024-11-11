n, x = [int(i) for i in input().split()]
count=0
for i in range(n):
    sign, d = input().split()
    d = int(d)
    if sign == '+':
        x += d
    else:
        if x >= d:
            x -= d
        else:
            count += 1
print("{0} {1}".format(x, count))

n = int(input())
m = 0
while n > 0:
    p, q = [int(i) for i in input().split()]
    if q - p >= 2:
        m += 1
    else:
        pass
    n -= 1
print(m)
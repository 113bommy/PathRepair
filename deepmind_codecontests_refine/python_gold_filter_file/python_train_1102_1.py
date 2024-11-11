t = int(input())
for i in range(t):
    a, b = map(int, input().split())
    denom = a * b * 2

    if denom == 0:
        if b == 0:
            print('1')
        else:
            print('0.5')
        continue

    if a > 4 * b:
        nom = 2 * b * b
    else:
        nom = (b - a / 4.0 + b) / 2.0 * a
    
    print('%.9f' % ((denom - nom) * 1.0 / denom))

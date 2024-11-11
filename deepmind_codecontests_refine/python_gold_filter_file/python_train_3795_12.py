s = 1
n = int(input())
while s <= n:
    print((n - s) // 2 * '*' + s * 'D' + (n - s) // 2 * '*')
    s += 2
s = n - 2
while s > 0:
    print((n - s) // 2 * '*' + s * 'D' + (n - s) // 2 * '*')
    s -= 2    
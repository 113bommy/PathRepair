t = int(input())
while t != 0:
    a, b, n, m = map(int, input().split())
    if a > b:
        a, b = b, a
    if m > min(a, b) or a + b < m + n:
        print('no')
    else:
        print('yes')
    t -= 1
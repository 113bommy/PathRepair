t = int(input())

while t:
    k, n, a, b = [int(a) for a in input().split(" ")]
    p = (k - b * n) // (a - b)
    diff = ((k - b * n) / (a - b)) - p
    if p == 0 and diff == 0:
        print('-1')
    elif diff == 0:
        print(max(min(p - 1, n), -1))
    else:
        print(max(min(p, n), -1))
    t -= 1

a = list(map(int, input().split()))

def check(a):
    a = a[:]
    x = a[0]
    a[0] = 0
    for i in range(1, 14):
        a[i] += max(0, (x+14-i) // 14)
    a[0] = max(0, x // 14)
    return sum((x if x % 2 == 0 else 0 for x in a))

print(max((check(a[i:] + a[:i]) for i in range(14) if a[i] > 0)))

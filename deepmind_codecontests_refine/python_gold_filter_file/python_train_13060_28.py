def not_simple(x):
    for i in range(2, x // 2+1):
        if x % i == 0:
            return True
    return False

n = int(input())
x = n - 4
for i in range(4, x):
    if not_simple(x) and not_simple(i) and i + x == n:
        print(i, x)
        break
    x -= 1
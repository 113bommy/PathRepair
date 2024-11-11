# cf 1088 A 800
# a divisible by b
# a * b > x
# a / b < x
def f(x):
    for a in range(1, x + 1):
        for b in range(1, a + 1):
            if a % b == 0 and a * b > x and a // b < x:
                return (a, b)
    return None

x = int(input())
ans = f(x)
if ans is None:
    print(-1)
else:
    print(ans[0], ans[1])


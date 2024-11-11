def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a * b / gcd(a, b)

x, y, a, b = map(int, input().split(' '))
l = lcm(x, y)
print(int(b // l - (a - 1) // l))

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

while True:
    try:
        a, b = map(int, input().split())
        print(gcd(a, b), a * b // gcd(a, b))
    except:
        break
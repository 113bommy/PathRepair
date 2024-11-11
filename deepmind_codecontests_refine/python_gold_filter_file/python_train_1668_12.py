x, y = [int(x) for x in input().split()]
def gcd(a, b):
    m = a%b
    return gcd(b, m) if m else b
print(gcd(x, y))
        


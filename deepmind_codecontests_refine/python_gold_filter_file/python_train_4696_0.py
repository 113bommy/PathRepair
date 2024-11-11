def gcd(a,b):
    if b == 0:
        return a
    else: 
        return gcd(b, a % b)

a,b,x,y=map(int, input().split())

k = gcd(x,y)
x //= k
y //= k

print(min(a//x, b//y))

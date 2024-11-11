import math

a, b = map(int, input().split())

if a >= b:
    print(math.factorial(b))
elif a < b:
    print(math.factorial(a))
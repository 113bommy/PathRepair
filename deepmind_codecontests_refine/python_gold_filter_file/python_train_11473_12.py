from math import gcd
for _ in range(int(input())):
    print("finite" if gcd(*map(int, input().split())) <= 1 else "infinite")
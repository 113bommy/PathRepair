from math import gcd
for i in range(int(input())):
    print("Infinite" if gcd(*map(int,input().split())) - 1 else "Finite")

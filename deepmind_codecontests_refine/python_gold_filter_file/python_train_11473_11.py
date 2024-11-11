from math import gcd
 
t = int(input())
for _  in range(t):
    a, b = [int(x) for x in input().strip().split(' ')]
    if gcd(a,b) == 1:
        print("Finite")
    else:
        print("Infinite")
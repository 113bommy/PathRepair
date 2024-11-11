# from sys import exit
h1, h2 = [int(n) for n in input().split()]
k1, k2 = [int(n) for n in input().split()]
a, b, c, d = [int(n) for n in input().split()]

A = h1*a + h1//10*c
A += h2*b + h2//20*d
B = k1*a + k1//10*c
B += k2*b + k2//20*d

if A > B:
    print("hiroshi")
elif A < B:
    print("kenjiro")
else:
    print("even")


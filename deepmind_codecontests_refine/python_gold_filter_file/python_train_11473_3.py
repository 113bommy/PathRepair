import math
t = int(input())

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

def hello():
    a, b = map(int, input().split())
    if gcd(a, b) == 1:
        print("finite")
    else:
        print("inFinite")


for i in range(t):
    hello()

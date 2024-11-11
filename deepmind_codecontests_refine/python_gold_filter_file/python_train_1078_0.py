n = int(input())
b = 2*3*5*7

a = b * (10**(n - 1) // b + 1)

if a >= 10**n:
    print(-1)
else:
    print(a)
b = int(input())
g = int(input())
n = int(input())


if b + g == n:
    print(1)
else:
    print( min(b,g,n, b+g - n) + 1)

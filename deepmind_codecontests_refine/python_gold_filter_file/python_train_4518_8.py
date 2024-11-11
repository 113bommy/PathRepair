def uravnenie(a, b, n):
    for x in range(-1000, 1001):
        if a * (x ** n) == b:
            return x
    return "No solution"


A, B, N = [int(i) for i in input().split()]
print(uravnenie(A, B, N))

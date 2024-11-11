R = lambda : list(map(int, input().split()))
a, b, c = R(), R(), R()
def r(a, b, c):
    return [a[0] + b[0] - c[0], a[1] + b[1] - c[1]]
print(3)
print(*r(a,b,c))
print(*r(b,c,a))
print(*r(c,a,b))

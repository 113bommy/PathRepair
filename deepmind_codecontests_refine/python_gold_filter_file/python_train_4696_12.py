

def nod(a, b):
    if b == 0:
        return a
    return nod(b, a % b)

[a, b, x, y] = [int(i) for i in input().split()]
n = nod(x, y)
x /= n
y /= n
print(int(min(a // x, b // y)))
x, y = map(int, input().split())
x = bin(x)[2:]
y = bin(y)[2:]

if x == y:
    print("YES")
    exit(0)

for var in [x + '1', x.strip('0')]:
    for left in range(len(y) - len(var) + 1):
        right = len(y) - len(var) - left
        if '1' * left + var + '1' * right == y or '1' * left + var[::-1] + '1' * right == y:
            print("YES")
            exit(0)
print("NO")

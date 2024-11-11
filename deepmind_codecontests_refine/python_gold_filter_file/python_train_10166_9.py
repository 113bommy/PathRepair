P, Y = [int(_) for _ in input().split()]
if Y % 2 == 0:
    Y -= 1
while Y > P:
    f = 1
    for i in range(3, min(int(Y**0.5), P) + 1, 2):
        if Y % i == 0:
            f = 0
            continue
    if f:
        print(Y)
        exit()
    Y -= 2
print(-1)

a = 0
data = []
n = int(input())
for i in range(n):
    b = int(input())
    a += b
    data += [b]
for i in range(n):
    if data[i] % 2 == 0:
        print(data[i] // 2)
    elif a >= 0:
        print(data[i] // 2)
        a -= 1
    else:
        a += 1
        print((data[i] + 1) // 2)

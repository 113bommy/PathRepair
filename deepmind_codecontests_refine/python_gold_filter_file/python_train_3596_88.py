a, b = map(int, input().split())
rez = 0
for i in range(a):
    c, d = input().split()
    if c == '+':
        b += int(d)
    else:
        d = int(d)
        if b >= d:
            b -= d
        else:
            rez += 1
print(b, rez)


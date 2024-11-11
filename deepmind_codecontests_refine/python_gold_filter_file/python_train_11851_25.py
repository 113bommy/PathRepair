N = int(input())
if N == 3:
    print(2, 5, 63)
    exit()
a = []
i = 2
while len(a) < N-N%2-2 and i + 2 <= 30000:
    a.append(i)
    a.append(i+2)
    i += 6
b = []
i = 3
while len(a) + len(b) < N-N%2 and i + 6 <= 30000:
    b.append(i)
    b.append(i+6)
    i += 12
c = []
i = 6
while len(a) + len(b) + len(c) < N:
    c.append(i)
    i += 6
print(' '.join(map(str, a+b+c)))


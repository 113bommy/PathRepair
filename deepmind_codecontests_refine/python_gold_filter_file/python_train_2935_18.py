def read():
    return int(input())


n = read()
switch = True
a = []
for i in range(n):
    line = [None] * n
    for j in range(n):
        line[j] = "W" if (i + j) % 2 == 0 else "B"
    a.append(line)

for line in a:
    print("".join(line))
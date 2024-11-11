string = input()
numbers = string.split()
a = int(numbers[0])
b = int(numbers[1])
r = 0
c = 0
rows = [0 for x in range(a)]
columns = [0 for x in range(a)]
cells = []
for x in range(b):
    string = input()
    numbers = string.split()
    row = int(numbers[0]) - 1
    column = int(numbers[1]) - 1
    if rows[row] == 0:
        rows[row] = 1
        r += 1
    if columns[column] == 0:
        columns[column] = 1
        c += 1
    cells.append((a - r) * (a - c))
print(" ".join(map(str, cells)))
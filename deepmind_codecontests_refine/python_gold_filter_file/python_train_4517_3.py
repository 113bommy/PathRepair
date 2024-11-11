string = input()
values = string.split()
a, b = int(values[0]), int(values[1])
numbers = [x for x in range(1, a + 1)]
numbers[:b + 1] = numbers[:b + 1][::-1]
print(" ".join(map(str, numbers)))
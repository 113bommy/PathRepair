n = int(input(""))
data = sorted([int(a) for a in input("").split()])
move1 = 0
move2 = 0
for i in range(0, int(n / 2)):
    move1 += abs(data[i] - (2 * i + 1))
for i in range(0, int(n / 2)):
    move2 += abs(data[i] - (2 * i + 2))
if move1 < move2:
    print(move1)
else:
    print(move2)


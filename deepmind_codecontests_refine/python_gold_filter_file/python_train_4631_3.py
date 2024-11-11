number = list(map(int, list(input())))
for i in range(len(number)):
    if number[i] >= 5:
        number[i] = 9 - number[i]
if number[0] == 0:
    number[0] = 9
number = list(map(str, number))
print(''.join(number))

inputting = input()
inputting = inputting.split(' ')
input_1 = inputting[0]
input_2 = inputting[1]

for i in range(0, int(input_2)):

    if str(input_1[-1]) != "0":
        input_1 = int(input_1)
        input_1 = int(input_1 - 1)
        input_1 = str(input_1)
    elif str(input_1[-1]) == "0":
        input_1 = int(input_1)
        input_1 = int(input_1/10)
        input_1 = str(input_1)
print(int(input_1))

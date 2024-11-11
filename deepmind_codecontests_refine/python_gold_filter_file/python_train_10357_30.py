import math

number = int(input())

number_list = ["zero","one","two","three","four","five","six","seven","eight","nine"]
teen_list = ["ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]
decades_list =["twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"]


if number <= 9:
    print(number_list[number])
elif number >= 10 and number <= 19:
    tens = number % 10
    print(teen_list[tens])
elif number > 19 and number <= 99:
    ones = math.floor(number/10)
    twos = ones - 2
    tens = number % 10
    if tens == 0:
        print(decades_list[twos])
    elif tens != 0:
        print(decades_list[twos] + "-" + number_list[tens])
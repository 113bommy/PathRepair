n = int(input())
result = 0
minOdd = 999999999


numbers = [int(i) for i in input().split(" ")]

for num in numbers:

    if(num % 2 != 0):
        minOdd = min(minOdd, num)


    result = result + num

if(result % 2 == 0):
    print(result)
else:
    print(result - minOdd)
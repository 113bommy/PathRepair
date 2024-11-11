threshold = int(input())
I = [int(x) for x in input()]
I.sort()
number = 0
temp = sum(I)
while temp < threshold:
    temp = temp + (9 - I[number])
    number = number + 1
print(number)

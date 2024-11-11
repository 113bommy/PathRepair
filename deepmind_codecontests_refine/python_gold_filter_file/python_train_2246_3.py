a = int(input())
b = int(input())
c = a + b
numbers = [a, b, c]
i = 0
while i < 3:
    a = numbers[i]
    razryad = 1
    new_number = 0
    while a > 0:
        last = a % 10
        if last != 0:
            new_number = last * razryad + new_number
            razryad *= 10
        a //= 10
    numbers[i] = new_number
    i += 1
print('YES' if numbers[0] + numbers[1] == numbers[2] else 'NO')
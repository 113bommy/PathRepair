def pol(a, b):
    numbers = [b]
    while a < b:
        if b%2 == 1:
            b = (b - 1)/10
        else:
            b /= 2
        numbers.append(b)
    numbers.sort()
    if a == b:
        return True, numbers
    else:
        return False, numbers
    
a, b = [int(s) for s in input().split()]
p, numbers = pol(a, b)
if p:
    print('YES')
    print(len(numbers))
    [print(int(s), end = ' ') for s in numbers] 
else:
    print('NO')

a, b = map(int, input().split())

if(a == b):
    print('infinity')
elif(a < b):
    print(0)
else:
    dif = a - b
    i = 1
    result = 0
    while i*i <= dif:
        if(dif % i == 0):
            if(i > b):
                result += 1
            if dif//i > b and i*i != dif:
                result += 1
        i += 1
    print(result)
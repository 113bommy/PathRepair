def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)


N = get_number()
count100 = 0
count200 = 0

for i in range(N):
    if(get_number() == 100):
        count100 += 1
    else:
        count200 += 1

if (count100 % 2 == 0):
    if (count200 % 2 == 0):
        print("YES")
    else:
        if(count100 > 0):
            print("YES")
        else:
            print("NO")
else:
    print("NO")

import sys

def dec_num(x):
    for i in range(len(x)):
        if x[i] == 2:
            x[i] = 5
        elif x[i] == 3:
            x[i] = 10
        elif x[i] == 4:
            x[i] = 50
        elif x[i] == 5:
            x[i] = 100
        elif x[i] == 6:
            x[i] = 500
        elif x[i] == 7:
            x[i] = 1000

def to_index(x):
    if x == 1:
        return 1
    elif x == 5:
        return 2
    elif x == 10:
        return 3
    elif x == 50:
        return 4
    elif x == 100:
        return 5
    elif x == 500:
        return 6
    elif x == 1000:
        return 7


def toNum(x):
    result = 0
    tmp = x[0]
    for i in range(len(x)):
        if tmp < x[i]:
            result += x[i]-tmp
        elif i < len(x)-1 and x[i] < x[i+1]:
            result += 0
        else:
            result += x[i]
        tmp = x[i] 

    return result

for line in sys.stdin.readlines():
    line = line.translate(str.maketrans('IVXLCDM', '1234567'))
    num = list(map(int, (' '.join(line)).split()))
    dec_num(num)
    print(toNum(num))
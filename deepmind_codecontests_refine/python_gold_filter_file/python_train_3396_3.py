a = 0
b = 0
f = 0
k = 0

def get_user_input():
    global a
    global b
    global f
    global k

    interval_info = input("").split()
    a = int(interval_info[0])
    b = int(interval_info[1])
    f = int(interval_info[2])
    k = int(interval_info[3])

def calc():
    global b
    m = 0
    count = 0
    B = b

    if B < (a-f) or B < f:
        return -1


    while m + 1 < k:
        if (m % 2 == 0) and (b < (a + (a-f))):
            count += 1
            m += 1
            b = B - (a - f)
            if b < (a-f):
                return -1

        elif (m % 2 != 0) and (b < (a + f)):
            count += 1
            m += 1
            b = B - f
            if b < f:
                return -1
        else:
            m += 1
            b = b - a

    if b - a < 0:
        count += 1

    return count

if __name__ == "__main__":
    get_user_input()
    print(calc())

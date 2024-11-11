# f = open("input.txt", "r")
# n = int(f.readline())
# print(n)
n = int(input())

for i in range(0, n):
    # l = f.readline()
    # print('------')
    # print(l)
    l = int(input())
    str_ = ''
    if int(l) <= 3:
        print('-1')
    elif int(l) == 4:
        print('3 1 4 2')
    else:
        k = int(l)
        t = k - (k + 1) % 2
        str_ = str_ + str(t)
        t = t - 2
        while t > 0:
            str_ = str_ + ' ' + str(t)
            t = t - 2
        str_ = str_ + ' 4 2'
        t = 6
        while t <= k:
            str_ = str_ + ' ' + str(t)
            t = t + 2
        print(str_)
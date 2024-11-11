a = input()
a_integer = int(a)
b = input()
b_len = len(b)
b_sum = 0
lis = []
c = 0
for i in range(len(b)):
    b_sum = b_sum + int(b[i])
for i in range(len(b)):
    lis.append(int(b[i]))
lis.sort()
if b_sum >= a_integer:
    print(c)
else:
    for i in range(len(b)):
        b_sum = b_sum + 9 - lis[i]
        c = c +1
        if b_sum >= a_integer:
            print(c)
            break
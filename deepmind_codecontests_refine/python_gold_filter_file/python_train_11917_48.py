a = int(input())
i = 1
p = 0
c = 0
if a == 1:
    print('1')
else:
    while a - i>=0 :
        i = i+1
        p = p+i
        a = a-p
        c = c+1
    print(c)
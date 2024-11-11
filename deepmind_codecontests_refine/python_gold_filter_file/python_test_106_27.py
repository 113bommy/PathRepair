t = int(input())

n = []

for i in range(t):
    n.append(input())

for i in n:
    if int(i) == 1:
        print(1)
    elif int(i) == 2:
        print('2 3')
    else:
        a = ''
        for j in range(2,int(i)+2):
            a += str(j)+' '
        a = a[0:-1]
        print(a)

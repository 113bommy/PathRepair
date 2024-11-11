from math import ceil
n = int(input())
m = ceil(n**0.1)
l1 = ['c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's']
if m**10 == n:
    for i in l1:
        print(i*m,end='')
    print()
else:
    for i in range(0,11):
        if (m**i)*((m-1)**(10-i))>=n:
            for j in range(i):
                print(l1[j]*(m),end='')
            for j in range(i,10):
                print(l1[j]*(m-1),end='')
            break
    print()
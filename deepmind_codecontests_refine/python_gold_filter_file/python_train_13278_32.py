from __future__ import print_function 

hate = 'I hate'
love = 'I love'
that = 'that'
it = 'it'
n = int(input())

if n == 1:
    print('I hate it')
else:
    for i in range(n):
        if i % 2 == 0:
            print(hate,end=' ')
            if i < n-1:
                print(that, end=' ')
        else:
            print(love, end=' ')
            if i < n-1:
                print(that, end=' ')
    print(it)




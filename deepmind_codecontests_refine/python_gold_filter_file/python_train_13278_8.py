# coding: utf - 8

t = int(input())
print('I hate ', end='')

for y in range (t - 1):
    if y % 2==0:
        print ('that I love ' ,end = '')
    else:
        print('that I hate ',end = '')

print('it')

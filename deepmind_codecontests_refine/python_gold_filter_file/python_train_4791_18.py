#! -*- coding:utf-8 -*-
n = int(input())
data = list(input().split())
data = [int(i) for i in data]

for i in range(n):
    print('node ',i+1,':',sep = '',end = '')
    print(' key = ',data[i],',',sep = '',end = '')

    if i != 0:
        print(' parent key = ',data[(i-1)//2],',',sep = '',end = '')
    
    if 2*i + 1 >= 0 and 2*i + 1 < n:
        print(' left key = ',data[2*i+1],',',sep = '',end = '')
    if 2*(i+1) >= 0 and 2*(i+1) < n:
        print(' right key = ',data[2*(i+1)],',',sep = '',end = '')

    print(' ')
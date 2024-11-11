# -*- encoding: utf-8 -*-

n, m, k = map(int, input().split())

print(m*(m-1)//2)
for i in range(m-1):
    for j in range(m-1-i):
        print('{} {}'.format(*((j+1, j+2)) if k == 0 else (j+2, j+1)))
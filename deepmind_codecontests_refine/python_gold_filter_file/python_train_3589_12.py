n, m = map(int, input().split())
a = list(map(int, input().split()))[1:]
b = list(map(int, input().split()))[1:]
na = [0] * n
nb = [0] * m
for i in a:
    na[i] = 1
for i in b:
    nb[i] = 1
for i in range(1000000) :
    x = i % n
    y = i % m
    na[x] = nb[y] = max(na[x], nb[y])
sumx = 0
sumy = 0
for i in na:
    sumx += i
for i in nb:
    sumy += i
if(sumx == n and sumy == m):
    print('Yes')
else :
    print('No')
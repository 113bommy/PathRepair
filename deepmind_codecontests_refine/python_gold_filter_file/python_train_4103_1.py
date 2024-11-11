import sys

n, m, k = map(int, input().split(' '))
ar = [0] * (n + 1);
tnt = [1000005] * (n + 1)
jael = 0;
for i in range(n):
    x, y = map(int, input().split(' '))
    ar[x], tnt[x] = x, min(tnt[x], y)

for i in range(n + 1):
    if(tnt[i] < 1000005):
        jael += tnt[i]

print(min(jael, k))


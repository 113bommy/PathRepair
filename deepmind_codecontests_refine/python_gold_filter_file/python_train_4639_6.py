import math as m
hx, hy = map(int, input().split());
n = int(input());

res = 1000;
for i in range(n):
    x, y, v = map(int, input().split());
    res = min((m.sqrt(pow((hx - x),2) + pow((hy - y), 2)))/v, res);
print(res)
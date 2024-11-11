import sys
n = int(input())
v = [-2] + [0] * n
m1, m2 = 0, 0
for x in map(int, input().split()):
    if x > m1:
        m1, m2, v[x] = x, m1, v[x] - 1
    elif x > m2:
        v[m1], m2 = v[m1] + 1, x
print(v.index(max(v)))

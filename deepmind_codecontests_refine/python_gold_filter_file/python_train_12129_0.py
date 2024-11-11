def f(i):
    return sum(a1[0 : i]) + sum(a2[i : ]) + b[i]

n = int(input())
a1 = list(map(int, input().split()))
a2 = list(map(int, input().split()))
b = list(map(int, input().split()))
m1 = 0
m2 = 1
if f(m1) > f(m2):
    (m1, m2) = (m2, m1)
for i in range(2, n):
    if f(i) < f(m1):
        (m1, m2) = (i, m1)
    elif f(i) < f(m2):
        m2 = i
print(f(m1) + f(m2))

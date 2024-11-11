from math import ceil
n = int(input())
n1 = n
p = 1
mas = set()
for i in range(2, ceil(n**.5) + 1):
    cnt = 0
    while n % i == 0:
        n = n//i
        mas.add(i)
        p *= i
mas.add(n1 // p)
p = 1
for i in mas:
    p *= i
print(p)
        
n = int(input())
a = [int(i) for i in input().split()]
b = 1
for i in range(n-1):
    if b % 2 != 0:
        c = a.index(max(a))
        a.pop(c)
        b += 1
    elif b % 2 == 0:
        c = a.index(min(a))
        a.pop(c)
        b += 1
print(*a)
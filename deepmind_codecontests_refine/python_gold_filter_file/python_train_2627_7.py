n = int(input())

b = [int(x) for x in input().split()]

a = []

aktualne_maximum = 0

for i in range(n):
    a.append(b[i]+aktualne_maximum)
    aktualne_maximum = max(aktualne_maximum, a[-1])

print(*a)

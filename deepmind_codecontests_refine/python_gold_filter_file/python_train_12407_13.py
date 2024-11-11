n = int(input())
s = list(map(int, input()))
lamps = []
for i in range(n):
    a, b = map(int, input().split())
    lamps.append([a, b])
calcm = 0
for i in range(10000):
    calc = 0
    j = 0
    for el in lamps:
        if i >= el[1] and (i - el[1]) % el[0] == 0:
            s[j] = 1 - s[j]
        j += 1
    calcm = max(sum(s), calcm)
print(calcm)
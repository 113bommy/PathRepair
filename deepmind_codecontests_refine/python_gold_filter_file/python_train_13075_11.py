n, m = map(int, input().split())

daf = input()
daf2 = input()

min_cha = m
min_ind = set()

for i in range(m - n + 1):
    daf3 = daf2[i:i+n]
    ind = set()
    dif = 0
    for j in range(n):
        if daf3[j] != daf[j]:
            ind.add(j)
            dif += 1
    if dif <= min_cha:
        min_ind = ind
        min_cha = dif

print(min_cha)
for x in min_ind:
    print(x+1, end = ' ')

print()

w, m = map(int, input().split())
mass = []
while m > 0:
    mass.append(m % w)
    m //= w
mass.append(0)
for i in range(len(mass) - 1):
    if mass[i] >= w - 1:
        mass[i + 1] += 1
        mass[i] = 0
ok = 1
for i in range(len(mass)):
    if mass[i] > 1:
        ok = 0
print("NO" if ok == 0 and w != 2 else "YES")
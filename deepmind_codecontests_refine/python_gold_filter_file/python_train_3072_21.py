n = int(input())
x1, x2 = map(int, input().split())
mass = []
for i in range(n):
    k, b = map(int, input().split())
    mass.append((k,b))
tmp_mass = [0] * len(mass)
for i in range(len(mass)):
    tmp_mass[i] = (mass[i][1] + mass[i][0] * x1, mass[i][1] + mass[i][0] * x2)
tmp_mass.sort(key = lambda x: (x[0], x[1]))
#print(tmp_mass)
flag = False
#случай, когда k > 0
for i in range(n - 1):
    if (tmp_mass[i][1] > tmp_mass[i+1][1] and
        tmp_mass[i+1][0] != tmp_mass[i][0]):
        flag = True
        break
if flag:
    print('YES')
else:
    print('NO')

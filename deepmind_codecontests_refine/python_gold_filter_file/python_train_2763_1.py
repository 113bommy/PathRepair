n = int(input())
c = [0] * 10
for i in input(): c[int(i)] = 1
f1 = sum((c[1], c[2], c[3]))
f2 = sum((c[1], c[4], c[7], c[0]))
f3 = sum((c[3], c[6], c[9], c[0]))
f4 = sum((c[7], c[9], c[0]))
print('NO' if 0 in (f1, f2, f3, f4) else 'YES')



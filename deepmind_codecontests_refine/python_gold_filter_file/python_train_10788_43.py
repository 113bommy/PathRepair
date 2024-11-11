n = int(input())
a = [input() for i in range(n)]
p = 0
for j in range(n):
    if a[j][0] == '-':
        p += 1
if p > 1 and n-p > 3:
    print('NO')
elif n-p > 1 and p > 1:
    print('NO')
else:
    print('YES')
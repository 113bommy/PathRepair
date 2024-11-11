x = set()
for i in range(1,501):
    x.add(i * (i+1)/2)

n = int(input())
if n in x:
    print('YES')
else:
    print('NO')
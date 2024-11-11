n, k = map(int, input().split())
s = input()
d = {}
k1 = 2
for i in s:
    d[i] = d.get(i,0) + 1
for i in s:
    if d[i] > k:
        k1 = 1
        break
if k1 == 1:
    print('NO')
else:
    print('YES')

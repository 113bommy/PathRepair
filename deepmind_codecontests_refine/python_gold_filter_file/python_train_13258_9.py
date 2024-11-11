s, n = map(int, input().split())
flag = 0
l = []
for i in range(n):
    key, value = map(int, input().split())
    l.append((key, value))
l = sorted(l, key=lambda x: x[0])

for (key, value) in l:
    if s>key:
        s = s+value
    else:
        flag = 1
        print('NO')
        break
if flag == 0:
    print('YES')

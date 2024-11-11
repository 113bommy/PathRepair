l = []

for _ in range(3):
    l += list(map(int, input().split()))

for i in range(4):
    if l.count(i + 1) == 3:
        print('NO')
        break
else:
    print('YES')
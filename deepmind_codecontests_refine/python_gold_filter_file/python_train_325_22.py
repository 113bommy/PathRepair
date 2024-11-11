n, y, x = map(int, input().split())

st = input()
res = 0
for i in range(len(st) - 1, len(st) - y - 1, -1):
    if i != len(st) - x - 1:
        if st[i] == '1':
            res += 1
    else:
        if st[i] == '0':
            res += 1
print(res)

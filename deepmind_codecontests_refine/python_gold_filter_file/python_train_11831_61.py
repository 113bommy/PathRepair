s = input()

cnt = 0
for c in s:
    if (c in ['a', 'e', 'i', 'o', 'u']) or (c.isdigit() and c not in ['0', '2', '4', '6', '8']):
        cnt += 1

print(cnt)
from sys import stdin, stdout

ans = list(map(int, list(stdin.readline().strip())))
d = {}

for f in stdin.readline().strip():
    if int(f) in d:
        d[int(f)] += 1
    else:
        d[int(f)] = 1


for i in range(len(ans)):
    for j in range(10, ans[i], -1):
        if j in d and d[j]:
            ans[i] = j
            d[j] -= 1
            break

stdout.write(''.join(list(map(str, ans))))
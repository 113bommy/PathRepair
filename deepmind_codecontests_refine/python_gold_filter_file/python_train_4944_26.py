max_count = 1000
input()
a = list(map(int, input().split()[1:]))
b = list(map(int, input().split()[1:]))
i = 0
while len(a) - i > 0 and len(b) - i > 0 and i < max_count:
    if a[i] > b[i]:
        a.extend([b[i], a[i]])
    else:
        b.extend([a[i], b[i]])
    i += 1
print(-1 if i == max_count else ' '.join(map(str, (i, 1))) if len(b) - i == 0 else ' '.join(map(str, (i, 2))))
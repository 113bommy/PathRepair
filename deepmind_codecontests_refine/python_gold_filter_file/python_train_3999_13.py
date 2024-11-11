n = int(input())
a = ''
s = 0
for i in range(1, n + 1):
    q = a
    a = input()

    if i == 1:
        continue
    else:
        if q != a:
            s += 1
        else:
            continue

print(s+1)

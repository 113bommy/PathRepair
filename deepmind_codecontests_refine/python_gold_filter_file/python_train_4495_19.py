a = input().lower()
b = len(a)

m = []

for i in range(b):
    if a[i] in ('a','e','i','o','u','y'):
        continue
    else:
        m.append('.')
        m.append(a[i])

print(''.join(m))



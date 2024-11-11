a = [1, 7, 9, 10, 11, 31, 41, 51, 61, 81,
    37, 47, 57, 67, 87,
    39, 49, 59, 69, 89]

for i in range(13, 30):
    a.append(i)
for i in range(70, 80):
    a.append(i)
for i in range(90, 100):
    a.append(i)


s = int(input())

# for i in range(1, 100):
if s not in a:
    print('YES')
else:
    print('NO')

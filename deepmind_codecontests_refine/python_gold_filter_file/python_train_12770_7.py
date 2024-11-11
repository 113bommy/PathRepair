ans = [[i for _ in range(50)] for i in ['C', 'D', 'A', 'B'] for j in range(12)]

a, b, c, d = map(int, input().split())

a -= 1
b -= 1
c -= 1
d -= 1

i = j = 0
while a:
    a -= 1
    ans[i][j] = 'A'
    j += 2
    if j >= 50:
        j = 0
        i += 2
i = 12
j = 0
while b:
    b -= 1
    ans[i][j] = 'B'
    j += 2
    if j >= 50:
        j = 0
        i += 2
i = 24
j = 0
while c:
    c -= 1
    ans[i][j] = 'C'
    j += 2
    if j >= 50:
        j = 0
        i += 2
i = 36
j = 0
while d:
    d -= 1
    ans[i][j] = 'D'
    j += 2
    if j >= 50:
        j = 0
        i += 2

print('48 50')
print('\n'.join(''.join(i) for i in ans))
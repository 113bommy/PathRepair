n = int(input())
p = [int(i) for i in input().split()]

letters = ['a', 'i', 'o', 'u', 'e', 'y']

for i in range(n):
    row = input()
    for c in row:
        if c in letters:
            p[i] -= 1
    if not p[i] == 0:
        print('NO')
        exit()
print('YES')

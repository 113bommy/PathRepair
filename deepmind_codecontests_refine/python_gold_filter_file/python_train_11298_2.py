n = int(input())
p = {'r':[], 'w':[], 'm':[], 'c':[]}
for i in range(n):
    a, b = input().split()
    if b[1] in ['h', 'o']: b = 'w'
    else: b = b[0]
    p[b].append(a)
for i in ['r', 'w', 'm', 'c']:
    if p[i]: print('\n'.join(j for j in p[i]))
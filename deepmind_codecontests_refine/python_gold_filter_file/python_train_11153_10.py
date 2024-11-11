n = int(input())
g = input()
G = [0] * (n + 1)
R = [0] * (n + 1)
B = [0] * (n + 1)
for i in range(n):
    G[i] = min(R[i - 1] + (1 if g[i] != 'G' else 0), B[i - 1] + (1 if g[i] != 'G' else 0))
    R[i] = min(G[i - 1] + (1 if g[i] != 'R' else 0), B[i - 1] + (1 if g[i] != 'R' else 0))
    B[i] = min(G[i - 1] + (1 if g[i] != 'B' else 0), R[i - 1] + (1 if g[i] != 'B' else 0))
print(min(G[-2], R[-2], B[-2]))
current = ''
if G[-2] == min(G[-2], R[-2], B[-2]):
    current = 'G'
elif B[-2] == min(R[-2], B[-2]):
    current = 'B'
else:
    current = 'R'
A = []
for i in range(n - 1, -1, -1):
    A.append(current)
    if current == 'G':
        if R[i - 1] + (1 if g[i] != 'G' else 0) < B[i - 1] + (1 if g[i] != 'G' else 0):
            current = 'R'
        else:
            current = 'B'
    elif current == 'R':
        if G[i - 1] + (1 if g[i] != 'R' else 0) < B[i - 1] + (1 if g[i] != 'R' else 0):
            current = 'G'
        else:
            current = 'B'
    else:
        if R[i - 1] + (1 if g[i] != 'B' else 0) < G[i - 1] + (1 if g[i] != 'B' else 0):
            current = 'R'
        else:
            current = 'G'
A.reverse()
print(''.join(A))
n = int(input())
s = [[0, 0], [0, 0]]

for i in range(n):
    x = [int(s) for s in input().split(' ')]
    s[x[0] - 1][0] += x[1]
    s[x[0] - 1][1] += x[2]

for server in s:
    if server[0] >= server[1]:
        print('LIVE')
    else:
        print('DEAD')

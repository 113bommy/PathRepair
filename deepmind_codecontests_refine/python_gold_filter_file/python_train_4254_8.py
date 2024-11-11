n, m = map(int, input().split())
nnode = [0]*n
for _ in range(m):
    a, b = map(int, input().split())
    nnode[a-1] += 1
    nnode[b-1] += 1
for i in nnode:
    if i%2==1:
        print('NO')
        break
else:
    print('YES')
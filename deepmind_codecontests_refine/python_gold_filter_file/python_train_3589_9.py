n, m = map(int, input().split())

boys = [0 for i in range(n)]
girls = [0 for i in range(m)]

b = list(map(int, input().split()))

for i in range(1, b[0]+1):
    boys[b[i]] = 1


g = list(map(int, input().split()))

for i in range(1, g[0]+1):
    girls[g[i]] = 1


for i in range(2 * n*m):
    if boys[i % n] or girls[i % m]:
        boys[i % n] = 1
        girls[i % m] = 1

flag = 1
for i in range(n):
    if not boys[i]:
        flag = 0

for i in range(m):
    if not girls[i]:
        flag = 0

if flag:
    print('Yes')
else:
    print('No')
        
        

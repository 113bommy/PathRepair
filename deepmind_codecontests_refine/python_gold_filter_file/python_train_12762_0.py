n = int(input())
p = list(map(int, input().split(' ')))
a = list(map(int, input().split(' ')))
b = list(map(int, input().split(' ')))
used = [False] * n

ma = [[], [], []]
mb = [[], [], []]

for i in range(n):
    ma[a[i] - 1].append(i)
    mb[b[i] - 1].append(i)

for i in range(3):
    ma[i].sort(key = lambda x: -p[x])
    mb[i].sort(key = lambda x: -p[x])

m = int(input())
c = list(map(int, input().split(' ')))
ans = [0] * m
for i in range(m):
    x = c[i] - 1

    def tryone(a):
        while len(a[x]) > 0 and used[a[x][len(a[x]) - 1]]:
            a[x].pop()
        if len(a[x]) == 0:
            return -1
        else:
            return a[x][len(a[x]) - 1]

    c1 = tryone(ma)
    c2 = tryone(mb)

    if c1 == -1 and c2 == -1:
        ans[i] = -1
    elif c1 == -1 or (c2 != -1 and p[c2] < p[c1]):
        used[c2] = True
        ans[i] = p[c2]
    else:
        used[c1] = True
        ans[i] = p[c1]

print(' '.join(list(map(str, ans))))

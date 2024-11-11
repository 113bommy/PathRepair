n = int(input())
l = [*map(int, input())]
d = {}
for i, j in enumerate(map(int, input().split())):
    d[i + 1] = j

i = 0
while i < n and d[l[i]] <= l[i]:
    i += 1
while i < n and d[l[i]] >= l[i]:
    l[i] = d[l[i]]
    i += 1
print(''.join(map(str, l)))
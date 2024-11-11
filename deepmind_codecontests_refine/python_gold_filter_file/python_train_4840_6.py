n = int(input())

a = []

for i in range(n):
    ma = list(int(s) for s in input().split(' '))
    if not ((1 in ma) or (3 in ma)):
        a.append(i + 1)


print(len(a))
for x in a:
    print(x, end=' ')
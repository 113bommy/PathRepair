from sys import exit

n, A = map(int, input().split())

c = list(map(int, input().split()))
d = {i: 0 for i in set(c) - set([A])}
ca = 0

for i in c:
    if i == A:
        ca += 1
    else:
        if i not in d: continue
        if d[i] < ca:
            d.pop(i)
        else:
            d[i] += 1

for i in d:
    if d[i] >= ca:
        print(i)
        exit(0)
print(-1)

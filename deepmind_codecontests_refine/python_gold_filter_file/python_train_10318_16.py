from collections import Counter

n = int(input())
S = [int(i) for i in input().split()]

c = Counter(S)
V = list(c.values())
cnt1 = V.count(1)
cnt2 = V.count(2)
if cnt1 % 2 == 1 and cnt1 + cnt2 * 2 == n:
    print('NO')
    exit()

d = dict()

s = ['A', 'B']
i = 0
flag = cnt1 % 2 == 1
for k, v in c.items():
    if v == 1:
        d[k] = [s[i]]
        i = (i+1) % 2
    elif flag and v >= 3:
        d[k] = ['B'] + ['A'] * (v - 1)
        flag = False
    else:
        d[k] = ['A'] * v

print('YES')
for s in S:
    print(d[s].pop(), end='')
print()
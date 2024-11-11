import sys

s = input()
n = len(s)
smallest = ['']*(n-1) + [s[-1]]
for i in range(n-2, -1, -1):
    smallest[i] = min(smallest[i+1], s[i])

t, u = [], []

for i in range(n):
    while t and t[-1] <= smallest[i]:
        u.append(t.pop())
    if s[i] == smallest[i]:
        u.append(s[i])
    else:
        t.append(s[i])

u += t[::-1]
print(*u, sep='')

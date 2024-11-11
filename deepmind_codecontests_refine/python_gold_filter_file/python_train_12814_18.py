import sys, math
n = map(int, input())
s = list(input())
t = list(input())

if sorted(s) != sorted(t):
    print(-1)
    sys.exit()

a = []
for k, c in enumerate(t):
    i = s.index(c)
    for j in reversed(range(1, i+1)):
        a.append(j+k)
    s.pop(i)

print(len(a) or 0)
print(' '.join(str(i) for i in a))

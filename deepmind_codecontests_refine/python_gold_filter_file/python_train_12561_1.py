import sys

n, a, b = map(int, sys.stdin.buffer.readline().decode('utf-8').split())
creature = [list(map(int, line.decode('utf-8').split()))
            for line in sys.stdin.buffer]

creature.sort(key=lambda x: -x[0]+x[1])

if b == 0:
    print(sum(x for _, x in creature))
    exit()

base = 0
for i in range(min(n, b)):
    base += max(creature[i])
for i in range(min(n, b), n):
    base += creature[i][1]

ans = base
mul = 1 << a

for i in range(min(n, b)):
    ans = max(
        ans,
        base - max(creature[i]) + creature[i][0] * mul
    )

base = base - max(creature[min(n, b)-1]) + creature[min(n, b)-1][1]
for i in range(min(n, b), n):
    ans = max(
        ans,
        base - creature[i][1] + creature[i][0] * mul
    )

print(ans)

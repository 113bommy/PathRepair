n = int(input())

a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

pos = [0] * (n + 1)
for i in range(n):
    pos[a[i]] = i

for i in range(n):
    pos[b[i]] -= i
    if pos[b[i]] < 0:
        pos[b[i]] += n

counter = {}
for i in range(1, n + 1):
    if pos[i] in counter:
        counter[pos[i]] += 1
    else:
        counter[pos[i]] = 1

ans = 0
for i, v in counter.items():
    ans = max(ans, v)
print(ans)

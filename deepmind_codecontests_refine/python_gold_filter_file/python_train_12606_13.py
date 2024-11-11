n, m = map(int, input().split())
reduce = []
s = 0
ans = 0

for i in range(n):
    a, b = map(int, input().split())
    s += a
    reduce.append(a - b)

reduce.sort(reverse=True)

i = 0

while s > m:
    ans += 1
    s -= reduce[i]
    i += 1
    if i >= n:
        break

if s > m:
    print(-1)
else:
    print(ans)
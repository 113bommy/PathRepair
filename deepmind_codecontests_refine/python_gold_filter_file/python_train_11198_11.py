n, m = map(int, input().split())
ans, l, r = [0] * n, 0, float('inf')

for i in range(m):
    l1, r1 = map(int, input().split())
    if r1 - l1 < r - l:
        l, r = l1, r1

l -= 1
r -= 1
c = 0
for i in range(l, r + 1):
    ans[i] = c
    c += 1

for i in range(l - 1, -1, -1):
    if ans[i + 1]:
        ans[i] = ans[i + 1] - 1
    else:
        ans[i] = r - l

for i in range(r + 1, n):
    if ans[i - 1] < r - l:
        ans[i] = ans[i - 1] + 1
    else:
        ans[i] = 0

print(r - l + 1)
print(*ans)

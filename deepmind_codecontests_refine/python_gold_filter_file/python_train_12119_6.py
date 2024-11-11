import sys


n = int(input())
a = list(map(int, input().split()))
ans = 0
par = True
for i in range(n):
    if i == a[i]:
        ans += 1
for i in range(n):
    if i != a[i] and i == a[a[i]]:
        ans += 2
        par = False
        break
if n != 1 and ans < n and par:
    ans += 1
print(ans)
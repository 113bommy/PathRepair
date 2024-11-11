n = int(input())
a = [int(i) for i in input().split()]
s = sum(a)
m = max(a)
ans = -1
for k in range(m, m*10):
    if s < n*k - s:
        ans = k
        break
print(ans)

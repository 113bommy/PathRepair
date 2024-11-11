n = int(input())
a = list(map(int, input().split()))

ans = []
for i, x in enumerate(a):
    cycle = 0
    while a[i] > 0:
        cycle += 1
        tmp = a[i] - 1
        a[i] -= (n + 1)
        i = tmp
    ans.append(cycle)


n = max(ans)
ans.remove(n)
m = max(ans) if ans else 0
if m:
    ans.remove(m)
o = 0
for x in ans:
    o += x**2
print((n+m)**2 + o)
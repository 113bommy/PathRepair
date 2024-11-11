n, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
if a[-1] != 10 ** 9:
    a.append(10 ** 9)
k = 0
s = 0
j = 0
ans = []
for i in range(1, 150000):
    if i < a[j]:
        if s + i <= m:
            ans.append(i)
            s += i
    elif i == a[j]:
        j += 1
    if s >= m:
        break

print(len(ans))
print(*ans)

l1 = [int(i) for i in input().split(' ')]
n = l1[0]
k = l1[1]
x = l1[2]
a = [int(i) for i in input().split(' ')]
a.sort()
gaps = []
ans = 1
for i in range(n - 1):
    if a[i + 1] - a[i] > x:
        gaps.append((a[i + 1] - a[i] - 1) // x)
gaps.sort()
for i in range(len(gaps)):
    if k >= gaps[i]:
        k -= gaps[i]
    else:
        ans += 1
print(ans)
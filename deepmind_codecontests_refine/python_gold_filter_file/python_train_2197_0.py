n, work, gap = map(int, input().split())
a = list(map(int, input().split()))
a = sorted([(a[i], i) for i in range(n)])
ret = [0] * n
day = 0
left = right = 0
while right < n:
    if a[right][0] - a[left][0] <= gap:
        day += 1
        ret[a[right][1]] = day
    else:
        ret[a[right][1]] = ret[a[left][1]]
        left += 1
    right += 1
print(day)
print(*ret)

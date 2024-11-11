n = int(input())
s1 = list(map(int, input().split()))
s2 = list(map(int, input().split()))
a = n * [0]
for i in range(n):
    if s1[i] == s2[i]:
        a[i] = s1[i]
if a.count(0) == 2:
    if s1[a.index(0)] not in s2 and s2[n - a[::-1].index(0) - 1] not in s1:
        a[a.index(0)] = s1[a.index(0)]
        a[a.index(0)] = s2[a.index(0)]
    elif s2[a.index(0)] not in s1 and s1[n - a[::-1].index(0) - 1] not in s2:
        a[a.index(0)] = s2[a.index(0)]
        a[a.index(0)] = s1[a.index(0)]
else:
    ans = 0
    for i in range(1, n + 1):
        if s1[a.index(0)] != i and s2[a.index(0)] != i and i not in a:
            a[a.index(0)] = i
            break
print(*a)

n = int(input())
a = [int(i) for i in input().split()]
a.sort()
i = 1
ans = 1
awp = 1
while i <= len(a) - 1:
    if a[i] == a[i - 1]:
        ans += 1
        if ans > awp:
            awp = ans
    else:
        ans = 1
    i += 1
print(awp, len(set(a)))
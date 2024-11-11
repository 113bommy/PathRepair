n = list(map(int, input().split()))
peb = list(map(int, input().split()))
ans = 0
for i in range(0, n[0]):
    if peb[i] % n[1] == 0:
        ans += peb[i] / n[1]
    else:
        ans += int(peb[i] / n[1]) + 1
if ans % 2 == 0:
    print(int(ans/2))
else:
    print(int(ans/2) + 1)
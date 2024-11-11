n = int(input())
l = list(map(int, input().split()))
ans = 0
for i in range(1, n):
    if (l[i] == 2 or l[i] == 3) and l[i - 1] != 1:
        print('Infinite')
        exit()
    else:
        if l[i] == 1 and l[i - 1] == 2:
            ans += 3
        if l[i] == 1 and l[i - 1] == 3:
            ans += 4
        if l[i] == 2:
            if i >= 2 and l[i - 2] == 3:
                ans += 2
            else:
                ans += 3
        if l[i] == 3:
            ans += 4
print('Finite')
print(ans)

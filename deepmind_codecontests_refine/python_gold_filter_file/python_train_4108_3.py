n = int(input())
#n = 22000
a = input().split(' ')
#a = ['100000'] * 22000
counted = [0] * (10 ** 5 + 2)
flag = a[0]
flag2 = 0
for i in range(0, n):
    counted[int(a[i])] += 1
    if flag != a[i]:
        flag2 = 1
if flag2 == 1:
    ans = [0] * (10 ** 5 + 1)
    ans[0] = 0
    ans[1] = counted[1]
    for i in range(1, 10 ** 5 + 1):
        if i != 1:
            ans[i] = max(ans[i - 1], ans[i - 2] + counted[i] * i)
    print(ans[n])
else:
    print(n * int(a[0]))
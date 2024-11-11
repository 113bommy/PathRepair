
n, x = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
k1, k2, k3 = 0, 0, 0
sum, v = 0, 0
flag = False
for i in range(n):
    if a[i] < x:
        k1 += 1
    if a[i] > x:
        k2 += 1
    if a[i] == x:
        k3 += 1
if k3 == 0:
    sum = abs(k1 - k2)
    if k1 >= k2: sum += 1
else:
    if k1 > k2:
        sum = 2 * k1 - n
        if not(k1 < (sum + n + 1) // 2 <= k1 + k3):
            sum += 1
    else:
        sum = k2 - k1 - k3
        if not(sum + k1 - v < (sum + n + 1) // 2 <= sum + k1 + k3):
            sum += 1
if sum < 0: sum = 0
print(sum)
n, m = list(map(int, input().split()))
l1 = [100000000000] + list(map(int, input().split())) + [10000000000]
l2 = [1] + list(map(int, input().split())) + [1]
sums = [0] * (n + m + 2)
uk1 = 0
uk2 = 1
while l2[uk2] != 1:
    uk2 += 1
while True:
    for i in range(uk1 + 1, uk2):
        if abs(l1[uk1] - l1[i]) <= abs(l1[uk2] - l1[i]):
            sums[uk1] += 1
        else:
            sums[uk2] += 1
    uk1 = uk2
    uk2 += 1
    while uk2 <= n + m + 1:
        if l2[uk2] == 1:
            break
        else:
            uk2 +=1
    if uk2 == n + m + 2:
        break
for i in range(1,len(sums) - 1):
    if l2[i] == 1:
        print(sums[i], end=' ')

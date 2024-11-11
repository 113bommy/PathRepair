n, k = map(int, input().split())
a = list(map(int, input().split()))

ruiseki = [0] * (n + 1)
for i in range(n):
    ruiseki[i+1] = ruiseki[i] + a[i]

li = []
for i in range(n):
    for j in range(i, n):
        tmp = format(ruiseki[j + 1] - ruiseki[i], '040b')
        li.append(tmp)

for i in range(40):
    cnt = 0
    new_li = []
    for j in range(len(li)):
        if li[j][i] == "1":
            new_li.append(li[j])
            cnt += 1
    if cnt >= k:
        li = new_li[0:]

ans = 2**41 -1
for i in range(k):
    ans = ans & int(li[i], 2)
print(ans)
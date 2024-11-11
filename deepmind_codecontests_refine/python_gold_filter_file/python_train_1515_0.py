L = list(map(int, input().split()))
sumv = sum(L)
dic = {}
for i in L:
    dic.setdefault(i, 0)
    dic[i] += 1
maxv = 0
for i in dic:
    if dic[i] == 2:
        maxv = max(maxv, 2 * i)
    elif dic[i] >= 3:
        maxv = max(maxv, 3 * i)
print(sumv - maxv)
n, k = [int(i) for i in input().split()]
data = [int(i) for i in input().split()]

dics = []
for i in range(20):
    dics.append({})

for d in data:
    ln = len(bin(d)) - 2
    for i in range(ln, -1, -1):
        # print(bin(d))
        if d not in dics[i]:
            dics[i][d] = [0]*20
            dics[i][d][ln - i] = 1
        else:
            dics[i][d][ln - i] += 1
        d >>= 1



mn = 1<<30
for i in range(20):
    dic = dics[i].values()
    found = False
    for d in dic:
        if sum(d) >= k:
            found = True
            left = k
            val = 0
            for i in range(20):
                if d[i] >= left:
                    val += i * (left)
                    break
                else:
                    val += i * d[i]
                    left -= d[i]

            # val = sum(d[:k])
            if val < mn:
                mn = val
    if not found:
        break


print(mn)

# ans2 = 0 
# vals = dics[ans].values()
# if len(vals) == 0:
#     pass
# else:
#     val = max(vals)
#     for d in dic
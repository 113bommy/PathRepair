def sum_without_one(arr, i):
    s = sum(arr)
    return [[s-x, (i+1, j+1)] for j, x in enumerate(arr)]


res = []
for i in range(int(input())):
    input()
    res.extend(sum_without_one(list(map(int, input().split())), i))
res.sort()
# print(res)
for i in range(1, len(res)):
    prev, curr = res[i-1], res[i]
    if prev[0] == curr[0] and prev[1][0] != curr[1][0]:
        print('YES')
        print(*prev[1])
        print(*curr[1])
        break
else:
    print('NO')

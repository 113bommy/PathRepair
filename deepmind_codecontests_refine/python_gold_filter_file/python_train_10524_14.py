n = int(input())

total = []
for _ in range(n):
    e,g,m,h = map(int, input().split())
    total.append(e+g+m+h)

#logic for solving
# print(total)
id = list(range(1,n+1))
for i in range(n):
    for j in range(i+1,n):
        if total[i] < total[j]:
            id[i], id[j] = id[j], id[i]
            total[i],total[j] = total[j], total[i]
        elif total[i] == total[j]:
            if id[i] > id[j]:
                id[i], id[j] = id[j], id[i]
                total[i],total[j] = total[j], total[i]
            else:
                total[i],total[j] = total[j], total[i]
# print(total, id)
rank = id.index(1) + 1
print(rank)

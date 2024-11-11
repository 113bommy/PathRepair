row,colum,k = map(int, input().split())
colums = [[] for i in range(colum)]
for i in range(row):
    temp = list(map(int, input().split()))
    for i in range(colum):
        colums[i].append(temp[i])
c = 0
ans = 0
for i in colums:
    count = 0
    for j in range(row-k+1):
        count = max(count,i[j:j+k].count(1))
        if count==k:
            break
    for j in range(row-k+1):
        if sum(i[j:j+k]) == count:
            c+=sum(i[:j])
            break
    ans+=count
print(ans,c)
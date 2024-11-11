n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int, input().strip().split())) +[i+1] )
k = int(input())
tables = list(map(int, input().strip().split()))

arr.sort(key = lambda x:-x[1])
ans = []
vis = [0 for i in range(k)]
for i in arr:
    mini = float('inf')
    temp = None
    for j in range(k):
        if vis[j] == 0 and tables[j] >= i[0] and tables[j] < mini:
            temp = i+[j+1]
            mini = tables[j]
    if temp:
        vis[temp[-1]-1] = 1
        ans.append(temp)

tot = 0
for i in ans:
    tot += i[1]

print(len(ans), tot)
for i in ans:
    print(*i[-2:])
# print(ans)
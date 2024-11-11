from operator import itemgetter
from collections import defaultdict
n = int(input())
coor = []
coor_list = defaultdict(list)
for _ in range(n):
    x, y = list(map(int,input().split()))
    coor.append((x,y))
    coor_list[y-x].append((x,y))
coor.sort(key=itemgetter(0,1))
order = {cor:i for i, cor in enumerate(coor)}
for x,y in coor_list.items():
    coor_list[x] = sorted(y, key=itemgetter(0,1),reverse=True)


nums = list(map(int, input().split()))
result = []
for i in nums:
    if i not in coor_list:
        print("NO")
        exit()
    else:
        result.append(coor_list[i].pop())
for i in range(1,n):
    if result[i][0] <= result[i-1][0] and result[i][1] <= result[i-1][1]:
        print("NO")
        exit()
print("YES")
for i in result:
    print(*i)
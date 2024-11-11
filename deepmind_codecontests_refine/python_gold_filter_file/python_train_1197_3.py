from collections import defaultdict
from operator import itemgetter

n = int(input())

points = []
point_weights = defaultdict(list)
for _ in range(n):
    x, y = tuple(map(int,input().split()))
    points.append((x, y))
    point_weights[y - x].append((x, y))

weights = list(map(int, input().split()))

points.sort(key=itemgetter(0, 1))

for w, p in point_weights.items():
    point_weights[w] = sorted(p, key=itemgetter(0, 1), reverse=True)

ans = "YES"
ans_arr = []
for weight in weights:
    if weight not in point_weights:
        ans = "NO"
        break
    else:
        if len(point_weights[weight]) == 0:
            ans = "NO"
            break
        else:
            ans_arr.append(point_weights[weight].pop())

for i in range(1, len(ans_arr)):
    if ans_arr[i][0] <= ans_arr[i - 1][0] and ans_arr[i][1] <= ans_arr[i - 1][1]:
        ans = "NO"
        break

print(ans)
if ans == "YES":
    for point in ans_arr:
        print(*point)

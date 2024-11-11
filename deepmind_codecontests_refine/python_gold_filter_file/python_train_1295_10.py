sum, limit = map(int, input().split())
ans = []
for i in range(limit, 0, -1):
    n = i & -i
    if n <= sum:
        sum -= n
        ans.append(i)

if sum == 0:
    print(len(ans))
    for i in ans: print(i, end=' ')
else:
    print(-1)
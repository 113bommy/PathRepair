n = int(input())
ls = list(map(int, input().split()))
ans = [0] * n
curr_max = ls[-1]
for i in range(n-2, -1, -1):
    if ls[i] > curr_max:
        curr_max = ls[i]
    else:
        ans[i] = (curr_max - ls[i] + 1)

print(*ans)

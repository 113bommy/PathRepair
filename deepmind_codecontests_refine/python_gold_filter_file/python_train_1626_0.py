n = int(input())
line = list(map(int, input().split()))
ans = -1
for i in range(n + 1):
    ans1 = 0
    for j in range(n):
        if j < i and line[j] == 0:
            ans1 += 1
        elif j >= i and line[j] == 1:
            ans1 += 1
    ans = max(ans, ans1)
print(ans)
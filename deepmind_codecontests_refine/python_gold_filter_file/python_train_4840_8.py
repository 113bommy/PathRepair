n = int(input())
ans = []
for i in range(n):
    s = list(map(int, input().split()))
    count1 = 0
    countIn1 = 0
    for j in s:
        if j == 1 or j == 3:
            count1 += 1
        if j == -1:
            countIn1 += 1
    if count1 == 0 and countIn1 == 1:
        ans.append(i + 1)
print(len(ans))
print(*ans)
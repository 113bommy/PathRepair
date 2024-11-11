S = input()
n = len(S)

ans = [0] * n
cnt = 0

for i in range(n):
    if 'R' == S[i]:
        cnt += 1
        continue
    ans[i-1] += (cnt + 1) // 2
    ans[i] += cnt // 2
    cnt = 0

for i in range(n-1, -1, -1):
    if 'L' == S[i]:
        cnt += 1
        continue
    ans[i+1] += (cnt + 1) // 2
    ans[i] += cnt // 2
    cnt = 0
print(*ans)

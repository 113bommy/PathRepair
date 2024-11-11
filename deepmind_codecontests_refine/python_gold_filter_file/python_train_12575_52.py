n = int(input())
S = input()
ans = 0
for d in range(n):
    cnt = 0
    for i in range(n-d):
        if S[i] == S[d+i]:
            cnt += 1
        else:
            cnt = 0
        ans = max(ans, min(cnt, d))
print(ans)

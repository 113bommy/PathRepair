n = int(input())
s = input()

n += 1
s += "#"

ans = 0
for i in range(1, n):
    cnt = 0
    for j in range(n-i):
        if s[i+j] == s[j]:
            cnt += 1
        else:
            ans = max(ans, min(cnt, i))
            cnt = 0

print(ans)

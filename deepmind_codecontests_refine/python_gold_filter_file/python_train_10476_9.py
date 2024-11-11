s = input()
cnt = 0
lst = []
n = len(s)
for i in s:
    if i == "Q":
        cnt += 1
    lst.append(cnt)
ans = 0
for i in range(n):
    if s[i] == "A":
        ans += (lst[i]*(lst[n - 1] - lst[i]))
print(ans)
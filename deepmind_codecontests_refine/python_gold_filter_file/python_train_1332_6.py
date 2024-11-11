S = input()
tmp = S[0]
now = ""
ans = 1
for i in range(1, len(S)):
    now += S[i]
    if tmp != now:
        ans += 1
        tmp = now
        now = ""
print(ans)

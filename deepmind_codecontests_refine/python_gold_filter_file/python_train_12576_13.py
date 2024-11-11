n = int(input())
s = [input() for _ in range(n)]

ans, cnt = 0, [0, 0, 0]
for i in s:
    ans += i.count('AB')
    if i[0] == 'B' and i[-1] == 'A':
        cnt[0] += 1
    elif i[0] == 'B':
        cnt[1] += 1
    elif i[-1] == 'A':
        cnt[2] += 1

if cnt[1] + cnt[2] == 0:
    print(ans + max(cnt[0] - 1, 0))
else:
    print(ans + min(cnt[1], cnt[2]) + cnt[0])

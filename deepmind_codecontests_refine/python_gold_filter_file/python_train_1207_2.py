s = input().split()
n = int(s[0])
k = int(s[1])
ss = input().split()
s = sorted([int(word) for word in ss])
maxx = k
ans = 0
for diff in s:
    while maxx < ((diff + 1) >> 1):
        ans += 1
        maxx <<= 1
    maxx = max(maxx, diff)
print(ans)

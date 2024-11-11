n = int(input())
s = list(input())
f = [int(elem) for elem in input().split()]
ind = -1
for i in range(n):
    if f[int(s[i]) - 1] > int(s[i]):
        ind = i
        break
if ind == -1:
    for i in range(n):
        print(s[i], end='')
else:
    x = i
    while x < n and f[int(s[x]) - 1] >= int(s[x]):
        s[x] = f[int(s[x]) - 1]
        x += 1
    for i in range(n):
        print(s[i], end='')
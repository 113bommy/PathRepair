s = input().split()
w = int(s[0])
h = int(s[1])
k = int(s[2])
ans = 0
for i in range(k):
    ans += w*2+(h-2)*2
    w -= 4
    h -= 4
print(ans)
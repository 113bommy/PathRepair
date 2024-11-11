n = int(input())
a = list(map(int, input().split()))
ma = 0
ans = 0
for i in range(len(a)):
    ma = max(ma, a[i])
    if i + 1 == ma:
        ans += 1
print(ans)

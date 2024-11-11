n, k = map(int,input().split())
ai = list(map(int,input().split()))
num = 0
num2 = 0
ans = 0
for i in range(n):
    num2 += ai[i]
    num += min(8, num2 - num)
    ans += 1
    if num >= k:
        break
if num < k:
    ans = -1
print(ans)

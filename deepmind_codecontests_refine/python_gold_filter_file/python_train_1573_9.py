n = int(input())
s = 0
i = 1
ans = 0
while n - s > 0:
    s += i
    i = s + 1
    ans += 1
print(ans)

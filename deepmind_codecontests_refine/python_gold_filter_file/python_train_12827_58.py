n = int(input())
ans = 1
while(n > 1):
    ans += 1 / n
    n -= 1
print(ans)

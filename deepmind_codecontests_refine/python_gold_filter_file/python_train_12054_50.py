n = int(input())
ans = 0
for i in range(n+1):
    if i%3 and i%5:
        ans+=i
print(ans)
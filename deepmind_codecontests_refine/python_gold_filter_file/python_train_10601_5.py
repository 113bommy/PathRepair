x,y = map(int,input().split())
ans = 0
while y >= x:
    ans += 1
    x *= 2
print(ans)
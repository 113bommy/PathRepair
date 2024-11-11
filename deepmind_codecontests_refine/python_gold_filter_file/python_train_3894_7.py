r, b, g = [int(i) for i in input().split()]
ans = 0
for i in range(min(2,r,b,g)+1):
    ans = max(ans, (r-i)//3 + (b-i)//3 + (g-i)//3 + i)
print(ans)


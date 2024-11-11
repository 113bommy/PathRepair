r,g,b = map(int, input().split(' '))

ans = 0

q = min(r//3,g//3,b//3)

for i in range(min(r+1,g+1,b+1)-max(0,(q-1)*3)):
    ans = max(ans, i + (r-i)//3 + (g-i)//3 + (b-i)//3)

print(ans)

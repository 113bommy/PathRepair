n = int(input())
lst = list(map(int, input().split()))
s = 0
ans = 0
where = 0
for i in range(n):
    if lst[i] == 1:
        ans += 1
        where = 1
    if lst[i] == 0 and i != 0:
        if i + 1 < n and lst[i + 1] == 0:
            where = 0
        elif i + 1 < n:
            if where == 1:
                ans += 1
print(ans)          
                
        

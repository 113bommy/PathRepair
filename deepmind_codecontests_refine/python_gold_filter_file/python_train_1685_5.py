t = int(input())
for _ in range(t):
    n = int(input())
    days = list(map(int, input().split(' ')))
    
    min_global = days.pop()
    ans = 0    
    while days:
        last = days.pop()
        if min_global >= last:
            min_global = last
        else:
            ans += 1
    print(ans)

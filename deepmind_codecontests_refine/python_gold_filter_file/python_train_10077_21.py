M, D = map(int, input().split())

ans = 0
for d in range(1,D+1) :
    d1 = d%10
    d10 = d//10
    if d1 >= 2 and d10 >= 2 and d1*d10 <= M :
        ans += 1

print(ans)

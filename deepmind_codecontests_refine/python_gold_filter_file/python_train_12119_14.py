n = int(input())
a = list(map(int, input().split()))
ans = 0
t = 1
for i in range(n):
    if a[i] == i: ans += 1
    else:
        if t and i == a[a[i]]: ans += 2; t = 0
if t: print(min(ans+1,n))
else: print(ans)
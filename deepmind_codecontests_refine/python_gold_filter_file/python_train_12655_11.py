n,k = map(int,input().split())
l = list(map(int,input().split()))
x = 1
ans = 0
if n == 1:
    print(0)
    print(l[0])
else:
    while x < n:
        if l[x] + l[x-1] < k:
            ans += k - (l[x]+l[x-1])
            l[x] = l[x]+ k - (l[x]+l[x-1])
        x += 1
    print(ans)
    for _ in l:
        print(_,end = ' ')
n, k = map(int, input().split())
a = list(map(int, input().split()))
m = min(a)
c = []
if max(a)-min(a)>k:
    print("NO")
else:
    for i in a:
        d= []
        for j in range(m):
            d.append(1)
        c.append(d)
    for i in range(n):
        if a[i]>m:
            co = 1
            for j in range(m, a[i]):
                c[i].append(co)
                co+=1
    print("YES")
    for i in c:
        print(*i)
        

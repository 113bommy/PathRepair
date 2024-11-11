def dist(a,b):
    return (b-a)%n

n, m = map(int, input().split())

cnd = [0 for x in range(n+1)]
mn = [5000 for x in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    # print(a,b,dist(a,b))
    cnd[a] += 1
    mn[a] = min(mn[a], dist(a,b))
# print(mn)
# print(cnd)

for i in range(1,n+1):
    ans = 0
    for j in range(1,n+1):
        if cnd[j] > 0:
            ans = max(ans, dist(i,j) + n*(cnd[j]-1) + mn[j])
    print(ans, end=" ")

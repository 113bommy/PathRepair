n,m = map(int,input().split())
x = [0]*(n+1)
for i in range(n):
    x[i] = int(input())
x[n] = 1000000000
vert = []
for i in range(m):
    x1,x2,y = map(int,input().split())
    if x1 == 1:
        vert.append(x2)
vert.sort()
x.sort()
cur = 0
minicount = n+m
k = len(vert)
for i in range(n+1):
    while cur < k:
        if x[i] <= vert[cur]:
            break
        cur += 1
    minicount = min(minicount,k-cur+i)
print(minicount)

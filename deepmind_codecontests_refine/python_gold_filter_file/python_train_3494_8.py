n = int(input())
a = []
ans,u,v = 0,-1,-1
for i in range(n):
    t = [int(x) for x in input().split()]
    t.sort()
    if ans < t[0]:
        ans = t[0]
        u = v = i
    t.append(i)
    a.append(t)

from operator import itemgetter
a.sort(key=itemgetter(1,2,0),reverse=True)

i = 0
while i+1 < n:
    if a[i][1:3]==a[i+1][1:3]:
        t = min(a[i][0]+a[i+1][0],a[i][1])
        if ans < t:
            ans = t
            u = a[i][3]
            v = a[i+1][3]
    i += 1
    while (i==0 or a[i][1:3]==a[i-1][1:3]) and i+1<len(a):
        i += 1

if u == v:
    print(1)
    print(u+1)
else:
    print(2)
    print(u+1,v+1)


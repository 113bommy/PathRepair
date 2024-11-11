from bisect import *
n, k = map(int, input().split())
a = list(map(int, input().split()))

posi = 0
nega = 0
zero = 0
p = []
m = []

for i in range(n):
    if a[i] > 0:
        p.append(a[i])
        posi += 1
    elif a[i] < 0:
        nega += 1
        m.append(-a[i])
    else:
        zero += 1

p.sort()
m.sort()

if k <= posi*nega:
    l = 0
    r = 10**18
    while r - l > 1:
        mid = l+(r-l)//2
        count = k
        for i in range(len(p)-1, -1, -1):
            count -= nega-bisect_left(m, (mid-1)//p[i]+1)
            if count <= 0:
                break
        if count <= 0:
            l = mid
        else:
            r = mid
        #print(r, l)

    print(-l)

elif k <= posi*nega+zero*(zero-1)//2+zero*(posi+nega):
    print(0)

else:
    k -= posi*nega+zero*(zero-1)//2+zero*(posi+nega)
    l = 0
    r = 10**18
    while r - l > 1:
        mid = l+(r-l)//2
        count = k
        for i in range(len(p)):
            count -= max(bisect_right(p, (mid)//p[i])-i-1, 0)
            if count < 0:
                #continue
                break
        for i in range(len(m)):
            count -= max(bisect_right(m, (mid)//m[i])-i-1, 0)
            if count < 0:
                #continue
                break

        if count > 0:
            l = mid
        else:
            r = mid
    print(r)

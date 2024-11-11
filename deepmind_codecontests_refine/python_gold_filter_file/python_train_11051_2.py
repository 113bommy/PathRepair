a ,b= (int(i) for i in input().split())
c = [int(i) for i in input().split()]
d = [int(i) for i in input().split()]
leng = len(d)
e = sum(c)*leng
c.sort()
d.sort()
if c[-1] > d[0]:
    print(-1)
else:
    count = 0
    for i in range(len(d)):
        count += d[i]
    if c[-1] == d[0]:
        count -= c[-1] * leng
    else:
        count -= c[-1] * (leng-1)
        count -= c[-2]
    ans = e + count
    print(ans)
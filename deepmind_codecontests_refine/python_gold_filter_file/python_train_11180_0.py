n,m = map(int, input().split())
a = list(map(int, input().split()))
f = [1]*n
for i in range(2,n):
    f[i] = f[i-1]+f[i-2]
for i in range(m):
    t,l,r = map(int, input().split())
    if t==1:
        a[l-1] = r
    else:
        sum_lr = 0
        for x in range(r-l+1):
            sum_lr += f[x] * a[l+x-1]
        print(sum_lr%1000000000)

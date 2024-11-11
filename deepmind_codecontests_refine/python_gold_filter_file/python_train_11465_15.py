n = int(input())
ans = [0,-1,-1,-1, 2 , 1.381966011]
for i in range(6, 1001):
    r=ans[i-1]
    l=r-0.2
    while (i - (i - l) * l > 0.00000001):
        tm = (r + l) / 2
        if (i - tm) * tm > i:
            r = tm
        else:
            l = tm
    ans.append(l)
for i in range(n):
    t = int(input())
    if ans[t]==-1:
        print('N')
    else:
        print('Y', t-ans[t], ans[t])


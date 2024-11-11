n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
cnt = [0 for i in range(n+1)]

def lb(x):
    l, r = 0, n
    while l < r:
        m = (l+r)//2
        if a[m] < x:
            l = m + 1
        else:
            r = m
    return l

def ub(x):
    l, r = 0, n
    while l < r:
        m = (l+r)//2
        if a[m] <= x:
            l = m + 1
        else:
            r = m
    return l

for i in range(n):
    l = lb(b[i])
    r = ub(b[i])-1
    if l > r:
        continue
    if l < i and i <= r:
        cnt[l+n-i]+=1
        cnt[0]+=1
        cnt[r-i+1]-=1
    elif i <= l:
        cnt[l-i]+=1
        cnt[r-i+1]-=1
    elif i > r:
        cnt[l+n-i]+=1
        cnt[r+n+1-i]-=1

res = 0
ans = -1
for i in range(n):
    res += cnt[i]
    if(res == 0):
        ans = i
if ans == -1:
    print("No")
else:
    print("Yes")
    for i in range(n):
        print(b[(i-ans+n)%n],end=' ')
from sys import stdin
n,a,r,m = map(int,stdin.readline().split())
he = list(map(int,stdin.readline().split()))
st = min(he)
en = max(he)
ans = 10**20
while st <= en:
    mid1 = st+(en-st)//3
    mid2 = en-(en-st)//3
    re=ad=0
    for i in he:
        re += max(0,i-mid1)
        ad += max(0,mid1-i)
    if m < a+r:
        cost = min(re,ad)*m
        if re<ad:
            cost += (ad-re)*a
        else:
            cost += (re-ad)*r
    else:
        cost = re*r+ad*a
    re=ad=0
    for i in he:
        re += max(0,i-mid2)
        ad += max(0,mid2-i)
    if m < a+r:
        cost1 = min(re,ad)*m
        if re<ad:
            cost1 += (ad-re)*a
        else:
            cost1 += (re-ad)*r
    else:
        cost1 = re*r+ad*a
    if cost > cost1:
        st = mid1+1
    elif cost < cost1:
        en = mid2-1
    else:
        st = mid1+1
        en = mid2-1
    ans = min(ans,cost1,cost)
print(ans)
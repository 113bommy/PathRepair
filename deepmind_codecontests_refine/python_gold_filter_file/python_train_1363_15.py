n,k=map(int,input().split())
a=list(map(int,input().split()))

def max_sum(m):
    pref = [0]
    for i in (x-m for x in a):
        pref += [pref[-1]+i]
    ans = pref[k]
    min_p = 0
    for i in range(k,len(pref)):
        ans = max(ans, pref[i] - min_p);
        min_p = min(min_p, pref[i-k+1]);
    return ans
l = 0; r = 5e3
while abs(r - l) > 1e-6:
    m = (r+l)/2
    if max_sum(m) >= 0:
        l=m
    else:
        r=m
print(r)
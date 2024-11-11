
n, k = map(int, input().split())
a = list(map(int, input().split()))
d = list(map(int, input().split()))
pref=[0]
for i in range(n):
    pref.append(pref[-1]+a[i])
if k==0:
    ans=0
    for i in range(1,n+1):
        ans=max(ans,pref[-1]-pref[i-1]-d[i-1])
    print(ans)
elif k == 1:
    best = sum(a[:n-1]) - min(d[:n-1])
    
    other = sum(a)
    other -= sorted(d)[0]
    other -= sorted(d)[1]
 
    curr = sum(a)
    for i in range(n):
        if i:
            best = max(best, curr - d[i])
        curr -= a[i]
 
    o2 = sum(a) - min(a[1:]) - d[0]
    
    print(max((best,other,0, o2)))
else:
    print(max((sum(a) - min(d[:-1]),0,a[-1] - d[-1])))

a,b,c,d,k = map(int,input().split())
mx = max(a,c)
mn = min(b,d)
ans = mn - mx + 1
if mx<=k<=mn:
    ans-=1
print(max(ans,0))
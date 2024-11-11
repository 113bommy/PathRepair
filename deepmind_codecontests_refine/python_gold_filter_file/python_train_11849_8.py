n=int(input())
s=input()
mod=10**9+7
t=dict()
for c in s:
    t.setdefault(c,1)
    t[c]+=1
ans=1
for v in t.values():
    ans=ans*v%mod
print(ans-1)
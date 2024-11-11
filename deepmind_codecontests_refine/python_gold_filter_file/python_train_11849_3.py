import collections
n=int(input())
l=list(input())
c=collections.Counter(l)
s=set(l)
ans=1
for i in s:
    ans*=(c[i]+1)
ans=ans-1
print(ans%(10**9+7))
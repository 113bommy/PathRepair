from collections import Counter
n=int(input())
s=input()
cnt=Counter(s)
ans=1
for i in cnt.values():
    ans*=i+1
print((ans-1)%(10**9+7))
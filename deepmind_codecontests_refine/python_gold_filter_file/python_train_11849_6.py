n=int(input())
s=input()
from collections import Counter
d=Counter(list(s))
ans=1
for i in d:ans*=d[i]+1
ans-=1
print(ans%(10**9+7))
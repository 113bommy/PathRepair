import collections as c

N=int(input())
S=list(input())

S=list(c.Counter(S).items())
#print(S)

ans=1
for s in S:
  ans*=(s[1]+1)
print((ans-1)%(10**9+7))
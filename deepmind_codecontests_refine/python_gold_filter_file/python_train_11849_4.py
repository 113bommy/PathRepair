n=int(input())
s=list(input())
a=set(s)
ans=1
for i in a:
    ans=ans*(s.count(i)+1)%(10**9+7)
print(ans-1)
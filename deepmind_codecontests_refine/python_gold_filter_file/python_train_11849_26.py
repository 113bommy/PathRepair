input();s=input();a=set(s)
c=1
for i in a:c=c*(s.count(i)+1)%(10**9+7)
print(c-1)
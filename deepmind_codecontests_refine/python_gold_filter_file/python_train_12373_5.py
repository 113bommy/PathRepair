from collections import Counter

n=int(input())
c=Counter(input())
for i in range(n-1):
    c&=Counter(input())
s=''
for k,v in sorted(c.items()):
    s+=k*v
print(s)
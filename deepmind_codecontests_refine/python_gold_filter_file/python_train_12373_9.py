from collections import Counter

n=int(input())
count=Counter(input())
for i in range(n-1):
    count&=Counter(input())
s=''
for k,v in sorted(count.items()):
    s+=k*v
print(s)